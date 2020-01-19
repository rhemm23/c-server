#include "include/config.h"

/**
 * Initializes a config object from
 * a file path
 */
Server::Config::Config(char *path) {
  FILE *file;
  if((file = fopen(path, "r")) != NULL) {
    read(file);
    fclose(file);
  }
}

/**
 * Destroys a config object
 */
Server::Config::~Config() {
  delete this->entries;
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
        (*this->entries)[key] = tok;
      }
    }
  }
}

/**
 * Returns the value associated with
 * a specific key
 */
char *Server::Config::get_value(char *key) {
  return (*this->entries)[key];
}
