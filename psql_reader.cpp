#include <cstring>

#include "include/psql_reader.h"

/**
 * Get data at column field name
 */
char* Server::PSQLReader::operator[](std::string field_name) {
  return strdup(this->iterator[field_name].c_str());
}

/**
 * Get data at column index
 */
char* Server::PSQLReader::operator[](int index) {
  return strdup(iterator[index].c_str());
}

/**
 * Increments the result iterator
 */
bool Server::PSQLReader::read() {
  if(this->iterator == this->result.end()) {
    return false;
  } else {
    this->iterator++;
    return true;
  }
}
