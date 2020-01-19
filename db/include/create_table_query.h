#pragma once
#define CREATE_TABLE_QUERY_H

#include "struct_query.h"
#include "table.h"

namespace Server {

  /**
   * Represents a query to create a database table
   */
  class CreateTableQuery : public StructureQuery {
    private:
      Table *table;

    public:
      std::string get_up_sql() override;
      std::string get_down_sql() override;
      CreateTableQuery(Table *table);
  };
}
