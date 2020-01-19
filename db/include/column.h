#pragma once
#define COLUMN_H

namespace Server {

  /**
   * Represents a database table column
   */
  struct Column {
    char *name;
    bool nullable;
    char *data_type;
    bool primary_key;
    char *references;
  };
}
