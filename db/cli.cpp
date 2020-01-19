#include "include/migrator.h"
#include "../include/config.h"
#include "../include/db_conn.h"
#include "migrations/include/migration_list.h"

int main(int argc, char *argv[]) {
  if(argc == 2) {
    if(strcmp(argv[1], "update") == 0) {
      Server::Config config("./config.ini");
      Server::DbConnectionConfig db_config = {
        config["db_port"],
        config["db_name"],
        config["db_user"],
        config["db_pass"],
        config["db_addr"]
      };
      Server::DbConnection *conn = Server::DbConnectionFactory::connect_to_psql(&db_config);
      Server::MigrationList migration_list;
      Server::Migrator migrator(conn, migration_list.get_migrations());
      migrator.update();
    }
  }
  printf("Usage: migrator {update}\n");
  return 0;
}
