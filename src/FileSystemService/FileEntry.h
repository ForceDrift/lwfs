#pragma once
#include "Filesystem.h"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

class FileEntry {

private:
  Filesystem filesystem_;
  std::string entry_name_;

  std::vector<FileEntry> children_;

  std::string getEntryName(std::filesystem::file_type type);
  std::vector<FileEntry> getEntryChildren(std::filesystem::file_type type);

public:
  FileEntry(const std::filesystem::path &path)
      : filesystem_(path),
        entry_name_(getEntryName(this->filesystem_.metadata_.file_type_)),
        children_(getEntryChildren(this->filesystem_.metadata_.file_type_)) {}

  std::vector<std::string> getThisFileEntry() {}

  // overload for easy print debug
  //

  friend std::ostream &operator<<(std::ostream &out, FileEntry obj) {
    // get in readable format and return
    return out;
  }

  FileEntry(const FileEntry &) = delete;
  FileEntry &operator=(const FileEntry &) = delete;

  FileEntry(const FileEntry &&) = delete;

  FileEntry &operator=(const FileEntry &&) = delete;
  ~FileEntry() = default;
};
