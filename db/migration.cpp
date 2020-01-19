#include <stdlib.h>

#include "include/create_table_query.h"

#include "include/migration.h"

/**
 * Adds the primary key constraint to a
 * table column
 */
Server::Column *Server::Migration::PRIMARY_KEY(Server::Column *column) {
  column->primary_key = true;
  return column;
}

/**
 * Adds the not null constraint to a
 * table column
 */
Server::Column *Server::Migration::NOT_NULL(Server::Column *column) {
  column->not_null = true;
  return column;
}

/**
 * Creates a new database table
 */
Server::StructureQuery *Server::Migration::create_table(Server::Table *table) {
  return new Server::CreateTableQuery(table);
}
