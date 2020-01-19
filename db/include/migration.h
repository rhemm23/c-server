#pragma once
#define MIGRATION_H

#include <uuid/uuid.h>
#include <inttypes.h>
#include <stdio.h>

namespace Server { 

  /**
   * Represents a new database migration
   */
  class Migration {
    protected:
      void execute_sql(char *sql);
      char *NOT_NULL(char *column);
      char *VARCHAR2(uint8_t size);
      void create_table(char *schema, char *name, char *columns[]);

    public:
      virtual void up();
      virtual void down();
      virtual void get_id(uuid_t out);
  };
}
