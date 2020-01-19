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
      void read(FILE *file);
      std::map<std::string, std::string> entries;

    public:
      Config(std::string path);
      ~Config();

      std::string &operator[] (std::string);
      std::string get_value(std::string key);
  };
}
