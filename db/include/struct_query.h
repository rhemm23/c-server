#pragma once
#define QUERY_H

namespace Server {

  /**
   * Represents a database query that alters the 
   * structure of the database
   */
  class StructureQuery {
    public:
      virtual char *get_up_sql();
      virtual char *get_down_sql();
  };
}
