#include "include/psql_reader.h"

/**
 * Get data at column field name
 */
template<typename T>
T &operator[](std::string field_name) {
  return it[field_name];
}

/**
 * Get data at column index
 */
template<typename T>
T &operator[](int index) {
  return it[index];
}

/**
 * Increments the result iterator
 */
bool Server::PSQLReader::read() {
  if(this->it == this->result.end()) {
    return false;
  } else {
    this->it++;
    return true;
  }
}
