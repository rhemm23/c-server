#pragma once
#define CONFIG_H

#include <map>

#include <string.h>
#include <stdio.h>

namespace Server {

  /**
   * Represents a collection of key value pairs
   */
  class Config {
    private:
      struct CompareKey {
        bool operator()(char const *a, char const *b) const {
          return strcmp(a, b) < 0;
        }
      };

      void read(FILE *file);
      std::map<char*, char*, CompareKey> *entries;

    public:
      Config(FILE *file);
      Config(char *path);

      char *get_value(char *key);
  };
}
