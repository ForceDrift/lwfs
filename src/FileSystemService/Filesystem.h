#pragma once

#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <memory>
#include <new>
class Filesystem {

private:
  struct Metadata {
    uintmax_t size_;
    std::filesystem::file_type file_type_;
    std::filesystem::file_time_type last_modified_time_;
    std::filesystem::file_time_type time_created_;
    std::filesystem::perms permissions_;
  };

  Metadata metadata_;
  std::filesystem::path filepath_;
  std::filesystem::path absolute_path_;

  std::vector<Filesystem> children_;

  uintmax_t getFileSize(std::filesystem::path &file_path) const noexcept;

  std::filesystem::file_type
  getFileType(std::filesystem::path &file_path) const noexcept;

  std::filesystem::file_time_type

  getFileLastModified(std::filesystem::path &file_path) const noexcept;
  std::filesystem::file_time_type
  getTimeCreated(std::filesystem::path &file_path) const noexcept;

  std::filesystem::perms getFilePermissions(std::filesystem::path &file_path);

public:
  Filesystem(std::filesystem::path path)
      : filepath_(std::move(path)),
        metadata_{.size_ = getFileSize(path),
                  .file_type_ = getFileType(path),
                  .last_modified_time_ = getFileLastModified(path)} {}
  // remove copy constructor
  //
  Filesystem(const Filesystem &) = default;
  Filesystem &operator=(const Filesystem &) = default;
  // include move constructor
  //
  Filesystem(Filesystem &&) = default;
  Filesystem &operator=(Filesystem &&) = default;

  void loadChildren();
  void printTree(const std::string &prefix, bool isLast = true) const;
  bool isDirectory() const noexcept;
};
