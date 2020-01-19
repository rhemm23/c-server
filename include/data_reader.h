#pragma once
#define DATA_READER_H

namespace Server {
  
  /**
   * Represents a row of data
   */
  class Row {
    public:
      virtual int size();
      virtual void *get_column(int index);
  };

  /**
   * Reads the results of a select query
   */
  class DataReader {
    public:
      virtual Row *next();
  };
}
