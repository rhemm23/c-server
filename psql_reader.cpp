#include <cstring>

#include "include/psql_reader.h"

/**
 * Get data at column field name
 */
std::string &Server::PSQLReader::operator[](std::string field_name) {
  std::string res(this->iterator[field_name].c_str());
  return res;
}

/**
 * Get data at column index
 */
std::string &Server::PSQLReader::operator[](int index) {
  return (std::string)strdup(iterator[index].c_str());
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
