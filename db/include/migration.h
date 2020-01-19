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
      char *NOT_NULL(char *column);
      char *VARCHAR2(uint8_t size);
      char *PRIMARY_KEY(char *column);
      char *create_table(char *schema, char *name, char *columns[]);

    public:
      void up();
      void down();
      virtual char *get_id();
      virtual char **get_queries();
  };
}
