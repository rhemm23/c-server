#pragma once
#define PSQL_READER_H

#include <pqxx/pqxx>

#include "data_reader.h"

namespace Server {

  /**
   * Postgresql's data reader implementation
   */
  class PSQLReader : public DataReader {
    private:
      pqxx::result::const_iterator it;

    public:
      // Access by field name
      template<typename T>
      T &operator[](std::string field_name);

      // Access by column index
      template<typename T>
      T &operator[](int index);

      bool read() override;
      PSQLReader(pqxx::result result);
  };
}
