#pragma once
#define PSQL_READER_H

#include <string>
#include <pqxx/pqxx>

#include "data_reader.h"

namespace Server {

  /**
   * Postgresql's data reader implementation
   */
  class PSQLReader : public DataReader {
    private:
      pqxx::result result;
      pqxx::result::const_iterator iterator;

    public:
      // Access by field name
      char* operator[](std::string) override;

      // Access by column index
      char* operator[](int) override;

      bool read() override;
      PSQLReader(pqxx::result result);
  };
}
