#pragma once
#define MIGRATOR_H

namespace Server {

  /**
   * Manages database migrations
   */
  class Migrator {
    public:
      Migrator(char *db_user, char *db_pass);
  };
}
