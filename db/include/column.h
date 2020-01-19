#pragma once
#define COLUMN_H

#include <string>

namespace Server {

  /**
   * Represents a database table column
   */
  struct Column {
    bool unique;
    bool not_null;
    bool primary_key;
    std::string name;
    std::string data_type;
    std::string references;
  };
}
