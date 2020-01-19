#include "include/config.h"

/**
 * Initializes a config object from
 * a file path
 */
Server::Config::Config(std::string path) {
  FILE *file;
  if((file = fopen(path.c_str(), "r")) != NULL) {
    read(file);
    fclose(file);
  }
}

/**
 * Reads all lines from the specified file,
 * adding in valid entries
 */
void Server::Config::read(FILE *file) {
  int nread;
  size_t len;
  char *line, *tok;
  while((nread = getline(&line, &len, file)) != -1) {
    if((tok = strtok(line, "=")) != NULL) {
      char *key = tok;
      if((tok = strtok(NULL, "=")) != NULL) {
        this->entries[key] = tok;
      }
    }
  }
}

/**
 * Returns the value associated with
 * a specific key
 */
std::string Server::Config::get_value(std::string key) {
  return this->entries[key];
}

/**
 * Indexer override, returns the value associated
 * with the passed key value
 */
std::string &Server::Config::operator[](std::string key) {
  return this->entries[key];
}
