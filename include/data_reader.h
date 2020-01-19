#pragma once
#define DATA_READER_H

#include <string>

namespace Server {

  /**
   * Reads the results of a select query
   */
  class DataReader {
    public:
      virtual bool read();
      virtual char* operator[](int);
      virtual char* operator[](std::string);
  };
}
