#pragma once

#include "../Formatter/FileSystemFormatter.h"
#include "Filesystem.h"
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <memory> #include <ostream> #include <string>
#include <ostream>
#include <string>
#include <string_view>
#include <utility>

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

  const std::string &getName() const { return entry_name_; }

  friend std::ostream &operator<<(std::ostream &os, FileEntry obj) {
    // print name, metadata nad children
    std::string name = obj.getName();
    std::string size = getSizeString(obj.filesystem_.metadata_.size_);
    std::string type =
        getFileType(std::filesystem::status(obj.filesystem_.filepath_));

    std::string mod_time =
        getTimeString(obj.filesystem_.metadata_.last_modified_time_);

    os << name + " | " + size + " | " + type + " | " + mod_time;
    return os;
  }

  // overload for easy print debug
  //

  FileEntry(const FileEntry &) = delete;
  FileEntry &operator=(const FileEntry &) = delete;

  FileEntry(FileEntry &&) = default;

  FileEntry &operator=(FileEntry &&) = default;
  ~FileEntry() = default;
};
