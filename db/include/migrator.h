#pragma once
#define MIGRATOR_H

#include <map>
#include <vector>

#include "migration.h"

#include "../../include/db_conn.h"

namespace Server {

  /**
   * Manages database migrations
   */
  class Migrator {
    private:
      void setup();
      DbConnection *conn; 
      std::vector<Migration*> migrations;
      std::map<std::string, std::string> statuses;

    public:
      void update();
      Migrator(DbConnection *conn, std::vector<Migration*> migrations);
  };
}
