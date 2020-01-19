#pragma once
#define MIGRATION_LIST_H

#include <vector>

#include "../../include/migration.h"

namespace Server {

  /**
   * Collection of all migrations
   */
  class MigrationList {
    private:
      std::vector<Migration*> migrations;

    public:
      MigrationList();
      std::vector<Migration*> get_migrations();
  };
}
