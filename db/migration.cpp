#include <stdlib.h>

#include "include/migration.h"

/**
 * Runs a SQL query against the current
 * database connection
 */
void Server::Migration::execute_sql(char *sql) {
  
}

/**
 * Builds the SQL needed to declare a
 * varchar2 data column
 */
char *Server::Migration::VARCHAR2(uint8_t size) {
  const char* const SQL = "VARCHAR2(%hhu)";
  char *res;
  asprintf(&res, SQL, size);
  return res;
}

/**
 * Adds the primary key constraint to a
 * table column
 */
char *Server::Migration::PRIMARY_KEY(char *column) {
  const char* const SQL = "%s PRIMARY KEY";
  char *res;
  asprintf(&res, SQL, column);
  free(column);
  return res;
}

/**
 * Adds the not null constriant to a
 * table column
 */
char *Server::Migration::NOT_NULL(char *column) {
  const char* const SQL = "%s NOT NULL";
  char *res;
  asprintf(&res, SQL, column);
  free(column);
  return res;
}

/**
 * Creates a new database table
 */
void Server::Migration::create_table(char *schema, char *name, char *columns[]) {
  const char* const SQL = "CREATE TABLE %s.%s (%s);";

}
