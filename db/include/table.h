#pragma once
#define TABLE_H

#include "column.h"

namespace Server {

  /**
   * Represents a database table
   */
  struct Table {
    char *schema;
    char *name;
    int ncolumns;
    Column **columns;
  };
}
