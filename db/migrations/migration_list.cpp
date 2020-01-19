#include "include/user_migration.h"

#include "include/migration_list.h"

/**
 * Returns a list of all migrations
 */
std::vector<Server::Migration*> Server::MigrationList::get_migrations() {
  return this->migrations;
}

/**
 * Initializes the migration list
 */
Server::MigrationList::MigrationList() {
  this->migrations = {
    new Server::UserMigration()
  };
}
