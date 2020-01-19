#include <pqxx/pqxx>

#include "include/psql_conn.h"

#include "include/db_conn.h"

/**
 * Opens a postgresql database connection from
 * a database config
 */
Server::DbConnection *Server::DbConnectionFactory::connect_to_psql(Server::DbConnectionConfig *config) {
  char *conn_str;
  asprintf(&conn_str, "dbname=%s user=%s password=%s hostaddr=%s port=%hu", config->db_name, config->username, config->password, config->host_addr, config->port);
  pqxx::connection *raw_conn = new pqxx::connection(conn_str);
  free(conn_str);
  if(raw_conn->is_open()) {
    return new PSQLConnection(raw_conn, config);
  } else {
    return NULL;
  }
}
