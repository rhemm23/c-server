#pragma once
#define DATA_READER_H

namespace Server {

  /**
   * Reads the results of a select query
   */
  class DataReader {
    public:
      virtual bool read();
      
      template<typename T>
      virtual T &operator[](int index);

      template<typename T>
      virtual T &operator[](std::string field_name);
  };
}
