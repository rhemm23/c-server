#include "include/user_migration.h"

/**
 * Returns a string uuid to represent the id 
 * of the migration
 */
std::string Server::UserMigration::get_id() {
  return "1D2A1EA9-E9B8-4C7B-B6D1-A15191A82080";
}

/**
 * Returns queries to execute
 */
std::vector<Server::StructureQuery*> Server::UserMigration::get_queries() {
  return {
    create_table(new Table {
      "user",
      "user", {
        primary_key(column("id", "bigserial")),
        unique(not_null(column("username", "varchar(50)"))),
        not_null(column("first_name", "varchar(50)")),
        not_null(column("last_name", "varchar(50)")),
        not_null(column("pass_hash", "bytea")),
        not_null(column("pass_salt", "bytea")),
        not_null(column("date_created", "timestamp")),
        column("date_updated", "timestamp")        
      }
    })
  };
}
