#include <pqxx/pqxx>
#include <cstring>

#include "include/migrator.h"

#define DOWN "DOWN"
#define UP "UP"

/**
 * Initialize the migrator instance
 */
Server::Migrator::Migrator(DbConnection *conn, std::vector<Migration*> migrations) {
  this->migrations = migrations;
  this->conn = conn;
  setup();
}

/**
 * Create migration table if it does not exist,
 * and get migration statuses
 */
void Server::Migrator::setup() {
  std::string INSERT_SQL = "INSERT INTO public.migration (id, status) VALUES (%s, %s)";
  std::string SELECT_SQL = "SELECT id, status FROM public.migration;";
  std::string TABLE_SQL = "CREATE TABLE IF NOT EXISTS public.migration (\
    id uuid NOT NULL PRIMARY KEY,\
    status varchar(20) NOT NULL\
  );"; 
  if(conn->execute_sql(TABLE_SQL) != 0) {
    printf("Error - Failed to create migration table\n");
    exit(EXIT_FAILURE);
  }
  try {
    pqxx::nontransaction N(this->conn);
    pqxx::result R(N.exec(SELECT_SQL));
    for(pqxx::result::const_iterator i = R.begin(); i != R.end(); i++) {
      this->statuses[i[0].as<std::string>()] = i[1].as<std::string>();
    }
  } catch(const std::exception &e) {
    printf("%s\n", e.what());
    exit(EXIT_FAILURE);
  }
  for(int i = 0; i < this->migrations.size(); i++) {
    std::map<std::string, std::string>::iterator it = this->statuses.find(
        this->migrations[i]->get_id());
    if(it == this->statuses.end()) {
      char *query;
      asprintf(&query, INSERT_SQL.c_str(), this->migrations[i]->get_id().c_str(), DOWN);
      if(this->conn->execute_sql(query) != 0) {
        printf("Error - Failed to insert migration record\n");
        exit(EXIT_FAILURE);
      }
      free(query);
    }
  }
}

/**
 * Executes all migrations that have not executed yet
 */
void Server::Migrator::update() {
  std::string UPDATE_SQL = "UPDATE public.migration SET status='%s' WHERE id=%s";
  for(int i = 0; i < this->migrations.size(); i++) {
    std::string val = this->statuses[this->migrations[i]->get_id()];
    if(strcmp(val.c_str(), DOWN) == 0) {
      this->migrations[i]->up();
      this->statuses[this->migrations[i]->get_id()] = UP;
      char *res;
      asprintf(&res, UPDATE_SQL.c_str(), UP, this->migrations[i]->get_id());
      this->conn->execute_sql(res);
      free(res);
    }
  }
}
