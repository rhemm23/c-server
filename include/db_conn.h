#pragma once
#define DB_CONN_H

#include <inttypes.h>

namespace Server {
  
  /**
   * Values needed to open a database
   * connection
   */
  struct DbConnectionConfig {
    uint16_t port;
    char *db_name;
    char *username;
    char *password;
    char *host_addr;
  };

  /**
   * Represents a connection to a database
   */
  class DbConnection {
    public:
      virtual int execute_sql(char *sql);
  };

  /**
   * Generates database connections for various
   * database systems
   */
  class DbConnectionFactory {
    public:
      static DbConnection *connect_to_psql(DbConnectionConfig *config);
  };
}
