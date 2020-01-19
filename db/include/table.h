#pragma once
#define TABLE_H

#include <vector>
#include <string>

#include "column.h"

namespace Server {

  /**
   * Represents a database table
   */
  struct Table {
    std::string schema;
    std::string name;
    std::vector<Column*> columns;
  };
}
