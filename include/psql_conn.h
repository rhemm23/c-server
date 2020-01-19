#pragma once
#define PSQL_CONN_H

#include <pqxx/pqxx>

#include "db_conn.h"

namespace Server {

  /**
   * Represents a connection to a postgresql
   * database
   */
  class PSQLConnection : public DbConnection {
    private:
      DbConnectionConfig *config;
      pqxx::connection *conn;

    public:
      PSQLConnection(pqxx::connection *conn, Server::DbConnectionConfig *config); 
      ~PSQLConnection();

      int execute_sql(char *sql) override;
  };
}
