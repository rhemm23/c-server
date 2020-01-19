#include "include/db_conn.h"

Server::DbConnection Server::DbConnectionFactory::connect_to_psql(Server::DbConnectionConfig *config) {
  char *conn_str;
  asprintf(&conn_str, "dbname=%s user=%s password=%s hostaddr=%s port=%hu", config->db_name, config->username, config->password, config->host_addr, config->port);
  pqxx::connection conn(conn_str);
  if(conn.is_open()) {
    return conn;
  } else {
    
  }
}
