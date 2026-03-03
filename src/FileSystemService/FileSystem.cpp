#include "Filesystem.h"
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <memory>
#include <sys/stat.h>
#include <system_error>

uintmax_t
Filesystem::getFileSize(std::filesystem::path &file_path) const noexcept {
  std::error_code ec;
  if (!std::filesystem::is_regular_file(file_path, ec)) {
    return 0;
  }
  auto size = std::filesystem::file_size(file_path, ec);
  if (ec) {
    return 0;
  }

  return std::filesystem::file_size(file_path);
}

std::filesystem::file_type
Filesystem::getFileType(std::filesystem::path &file_path) const noexcept {
  return std::filesystem::status(file_path).type();
}

std::filesystem::file_time_type Filesystem::getFileLastModified(
    std::filesystem::path &file_path) const noexcept {

  return std::filesystem::last_write_time(file_path);
}

std::filesystem::file_time_type
Filesystem::getTimeCreated(std::filesystem::path &file_path) const noexcept {
  struct stat file_stats;
  auto create_time =
      std::chrono::seconds{file_stats.st_birthtimespec.tv_sec} +
      std::chrono::nanoseconds{file_stats.st_birthtimespec.tv_nsec};
  return static_cast<std::filesystem::file_time_type>(create_time);
}

std::filesystem::perms
Filesystem::getFilePermissions(std::filesystem::path &file_path) {
  return std::filesystem::status(file_path).permissions();
}

// std::vector<std::unique_ptr<Filesystem>>
//
// loadChildren(std::filesystem::path &file_path) noexcept {
//   std::vector<std::unique_ptr<Filesystem>> fs;
//
//   for (const auto &dir : std::filesystem::directory_iterator{file_path}) {
//     fs.emplace_back(std::make_unique<Filesystem>(dir));
//   }
//   return fs;
// }
//
bool Filesystem::isDirectory() const noexcept {
  return metadata_.file_type_ == std::filesystem::file_type::directory;
}

void Filesystem::loadChildren() {
  if (!isDirectory()) {
    return;
  }
  std::error_code ec;

  for (const auto &file : std::filesystem::directory_iterator(filepath_)) {
    if (ec) {
      continue;
    }
    Filesystem child(file.path());
    child.loadChildren();
    children_.push_back(std::move(child));
  }
}

// print tree

void Filesystem::printTree(const std::string &prefix, bool isLast) const {

  std::cout << prefix;

  if (!prefix.empty()) {
    std::cout << (isLast ? "└── " : "├── ");
  }

  std::cout << filepath_.filename().string();

  if (isDirectory()) {
    std::cout << "/";
  }

  if (!isDirectory()) {
    std::cout << metadata_.size_;
  }
  std::cout << '\n';

  std::string newPrefix = prefix;
  if (!prefix.empty()) {
    newPrefix += (isLast ? "    " : "│   ");
  }
  for (size_t i = 0; i < children_.size(); ++i) {
    bool lastChild = (i == children_.size() - 1);
    children_[i].printTree(newPrefix, lastChild);
  }
}
