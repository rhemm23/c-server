#pragma once
#define MIGRATION_H

#include <uuid/uuid.h>
#include <stdio.h>

#include "struct_query.h"
#include "column.h"
#include "table.h"

namespace Server { 

  /**
   * Represents a new database migration
   */
  class Migration {
    protected:
      /**
       * Column attributes
       */
      Column *unique(Column *column);
      Column *not_null(Column *column);
      Column *primary_key(Column *column);  
      Column *column(std::string name, std::string data_type);
      Column *references(Column *column, std::string references);

      /**
       * Structure queries
       */
      StructureQuery *create_table(Table *table);

    public:
      void up();
      void down();
      virtual std::string get_id();
      virtual std::vector<StructureQuery*> get_queries();
  };
}
