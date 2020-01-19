#pragma once
#define QUERY_H

#include <string>

namespace Server {

  /**
   * Represents a database query that alters the 
   * structure of the database
   */
  class StructureQuery {
    public:
      virtual std::string get_up_sql();
      virtual std::string get_down_sql();
  };
}
