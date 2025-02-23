#include "include/psql_conn.h"

/**
 * Creates and executes a postgresql transactional query
 * Returns 0 if successful, -1 otherwise
 */
int Server::PSQLConnection::execute_sql(char *sql) {
  try {
    pqxx::work transaction(*this->conn);
    transaction.exec(sql);
    transaction.commit();
    return 0;
  } catch(const std::exception &e) {
    fprintf(stderr, "%s\n", e.what());
    return -1;
  }
}

/**
 * Executes a query and returns a data reader to read
 * the results
 */
Server::DataReader *execute_reader(std::string sql) {
  pqxx::nontransaction N(this->conn);
  pqxx::result R(N.exec(sql));
  return new PSQLReader(R);
}

/**
 * Destroys the postgresql connection
 */
Server::PSQLConnection::~PSQLConnection() {
  this->conn.disconnect();
  delete this->conn;
}

/**
 * Creates a new postgresql connection instance
 */
Server::PSQLConnection::PSQLConnection(pqxx::connection *conn, Server::DbConnectionConfig *config) {
  this->config = config;
  this->conn = conn;
}
