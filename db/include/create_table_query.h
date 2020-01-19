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
      char *get_up_sql() override;
      char *get_down_sql() override;
      CreateTableQuery(Table *table);
  };
}
