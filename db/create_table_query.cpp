#include <sstream>

#include <string.h>

#include "include/column.h"

#include "include/create_table_query.h"

/**
 * Creates a new create table query
 */
Server::CreateTableQuery::CreateTableQuery(Server::Table *table) {
  this->table = table;
}

/**
 * Gets the SQL query text necessary to
 * create the table
 */
char *Server::CreateTableQuery::get_up_sql() {
  char *res;
  std::stringstream sql;
  sql << "CREATE TABLE ";
  sql << this->table->schema << ".";
  sql << this->table->name << " (";
  if(this->table->ncolumns > 0) {
    sql << "\n";
  }
  for(int i = 0; i < this->table->ncolumns; i++) {
    Column *column = this->table->columns[i];
    sql << "\t" << column->name << " ";
    sql << column->data_type;
    if(column->nullable) {
      sql << " NOT NULL";
    } else {
      sql << " NULL";
    }
    if(column->primary_key) {
      sql << " PRIMARY KEY";
    }
    if(column->references != NULL) {
      sql << " REFERENCES " << column->references;
    }
    if(i != this->table->ncolumns - 1) {
      sql << ",";
    }
    sql << "\n";
  }
  sql << ");";
  return strdup(sql.str().c_str());
}

/**
 * Gets the SQL query text necessary to
 * drop the table
 */
char *Server::CreateTableQuery::get_down_sql() {
  char *res;
  asprintf(&res, "DROP TABLE %s.%s;", this->table->name, this->table->schema);
  return res;
}
