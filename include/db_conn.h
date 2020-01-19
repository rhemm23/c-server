#pragma once
#define DB_CONN_H

#include <string>

namespace Server {
  
  /**
   * Values needed to open a database
   * connection
   */
  struct DbConnectionConfig {
    std::string port;
    std::string db_name;
    std::string username;
    std::string password;
    std::string host_addr;
  };

  /**
   * Represents a connection to a database
   */
  class DbConnection {
    public:
      virtual DataReader *execute_reader(std::string sql);
      virtual int execute_sql(std::string sql);
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
