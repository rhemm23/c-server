#include "include/migrator.h"

Server::Migrator::Migrator(DbConnection *conn) {
  this->conn = conn;
}
