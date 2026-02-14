#include "Filesystem.h"
#include <chrono>
#include <cstdint>
#include <ctime>
#include <filesystem>
#include <sys/stat.h>

std::string filetype_to_string(std::filesystem::file_status fs) {
  switch (fs.type()) {
  case std::filesystem::file_type::none:
    return "None";
  case std::filesystem::file_type::not_found:
    return "Not_found";
  case std::filesystem::file_type::regular:
    return "Regular";
  case std::filesystem::file_type::directory:
    return "Directory";
  case std::filesystem::file_type::symlink:
    return "Symlink";
  case std::filesystem::file_type::block:
    return "Block";
  case std::filesystem::file_type::character:
    return "Character";
  case std::filesystem::file_type::fifo:
    return "Fifo";
  case std::filesystem::file_type::socket:
    return "Socket";
  case std::filesystem::file_type::unknown:
    return "Unknown";
  default:
    return "Unknown";
  }
}

uintmax_t Filesystem::getFileSize(std::filesystem::path &file_path) {

  return std::filesystem::file_size(file_path);
}

std::string Filesystem::getFileType(std::filesystem::path &file_path) {
  return filetype_to_string(std::filesystem::status(file_path));
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
