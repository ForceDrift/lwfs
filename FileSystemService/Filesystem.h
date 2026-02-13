#pragma once

#include <cstdint>
#include <filesystem>
#include <iostream>
class Filesystem {
private:
  struct Metadata {
    uintmax_t size_;
    std::string file_type_;
    std::filesystem::file_time_type last_modified_time_;
    std::filesystem::file_time_type time_created_;
    std::filesystem::perms permissions_;
  };

  Metadata metadata_;
  std::filesystem::path filepath_;
  std::filesystem::path absolute_path_;

  uintmax_t getFileSize(std::filesystem::path &file_path);
  std::string getFileType(std::filesystem::path &file_path);
  std::filesystem::file_time_type

  getFileLastModified(std::filesystem::path &file_path);
  std::filesystem::file_time_type
  getTimeCreated(std::filesystem::path &file_path);

  std::filesystem::perms getFilePermissions(std::filesystem::path &file_path);
  // permissions, created, extension user owner, symmlink

public:
  Filesystem(std::filesystem::path path)
      : filepath_(path),
        metadata_{.size_ = getFileSize(path),
                  .file_type_ = getFileType(path),
                  .last_modified_time_ = getFileLastModified(path)} {}

  Filesystem(const Filesystem &) = delete;
  void operator=(const Filesystem &) = delete;

  // check Metadata {
  // } + other stuff
};
