#pragma once
#define MIGRATOR_H

#include "../../include/db_conn.h"

namespace Server {

  /**
   * Manages database migrations
   */
  class Migrator {
    private:
      DbConnection *conn;

    public:
      Migrator(DbConnection *conn);
  };
}
