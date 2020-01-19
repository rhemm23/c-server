#pragma once
#define USER_MIGRATION_H

#include "../../include/migration.h"

namespace Server {

  /**
   * Migration to add user table
   */
  class UserMigration : public Migration {
    public:
      std::string get_id() override;
      std::vector<StructureQuery*> get_queries();
  };
}
