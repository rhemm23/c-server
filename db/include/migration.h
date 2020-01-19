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
      Column *NOT_NULL(Column *column);
      Column *PRIMARY_KEY(Column *column);

      /**
       * Structure queries
       */
      StructureQuery *create_table(Table *table);

    public:
      void up();
      void down();
      virtual char *get_id();
      virtual StructureQuery **get_queries();
  };
}
