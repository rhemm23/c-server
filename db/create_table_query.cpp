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
std::string Server::CreateTableQuery::get_up_sql() {
  char *res;
  std::stringstream sql;
  sql << "CREATE TABLE ";
  sql << this->table->schema << ".";
  sql << this->table->name << " (";
  if(this->table->columns.size() > 0) {
    sql << "\n";
  }
  for(int i = 0; i < this->table->columns.size(); i++) {
    Column *column = this->table->columns[i];
    sql << "\t" << column->name << " ";
    sql << column->data_type;
    if(column->not_null) {
      sql << " NOT NULL";
    } else {
      sql << " NULL";
    }
    if(column->primary_key) {
      sql << " PRIMARY KEY";
    }
    if(!column->references.empty()) {
      sql << " REFERENCES " << column->references;
    }
    if(i != this->table->columns.size() - 1) {
      sql << ",";
    }
    sql << "\n";
  }
  sql << ");";
  return sql.str();
}

/**
 * Gets the SQL query text necessary to
 * drop the table
 */
std::string Server::CreateTableQuery::get_down_sql() {
  char *res;
  asprintf(&res, "DROP TABLE %s.%s;", this->table->name.c_str(), this->table->schema.c_str());
  return (std::string)res;
}
