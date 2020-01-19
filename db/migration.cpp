#include <stdlib.h>
#include <string.h>

#include "include/create_table_query.h"

#include "include/migration.h"

/**
 * Adds the unique contraint to a table column
 */
Server::Column *Server::Migration::unique(Server::Column *column) {
  column->unique = true;
  return column;
}

/**
 * Creates a new table column
 */
Server::Column *Server::Migration::column(std::string name, std::string data_type) {
  Column *column = new Column();
  column->name = name;
  column->data_type = data_type;
  return column;
}

/**
 * Adds the primary key constraint to a
 * table column
 */
Server::Column *Server::Migration::primary_key(Server::Column *column) {
  column->primary_key = true;
  return column;
}

/**
 * Adds the references constraint to a
 * table column
 */
Server::Column *Server::Migration::references(Server::Column *column, std::string references) {
  column->references = references;
  return column;
}

/**
 * Adds the not null constraint to a
 * table column
 */
Server::Column *Server::Migration::not_null(Server::Column *column) {
  column->not_null = true;
  return column;
}

/**
 * Creates a new database table
 */
Server::StructureQuery *Server::Migration::create_table(Server::Table *table) {
  return new Server::CreateTableQuery(table);
}
