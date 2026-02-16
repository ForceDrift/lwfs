#include "Filesystem.h"
#include <chrono>
#include <cstdint>
#include <ctime>
#include <filesystem>
#include <sys/stat.h>

uintmax_t Filesystem::getFileSize(std::filesystem::path &file_path) {

  return std::filesystem::file_size(file_path);
}

std::filesystem::file_type
Filesystem::getFileType(std::filesystem::path &file_path) {
  return std::filesystem::status(file_path).type();
}

std::filesystem::file_time_type
Filesystem::getFileLastModified(std::filesystem::path &file_path) {

  return std::filesystem::last_write_time(file_path);
}

std::filesystem::file_time_type
getTimeCreated(std::filesystem::path &file_path) {
  struct stat file_stats;
  auto create_time =
      std::chrono::seconds{file_stats.st_birthtimespec.tv_sec} +
      std::chrono::nanoseconds{file_stats.st_birthtimespec.tv_nsec};
  return static_cast<std::filesystem::file_time_type>(create_time);
}
std::filesystem::perms getFilePermissions(std::filesystem::path &file_path) {
  return std::filesystem::status(file_path).permissions();
}
