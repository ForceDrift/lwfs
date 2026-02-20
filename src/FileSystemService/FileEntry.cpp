#include "FileEntry.h"
#include <algorithm>
#include <cstddef>
#include <filesystem>

std::string FileEntry::getEntryName(std::filesystem::file_type type) {
  std::string entry_name;
  if (type == std::filesystem::file_type::regular) {
    // path
    entry_name = this->filesystem_.filepath_.filename().string();
  } else if (type == std::filesystem::file_type::directory) {
    entry_name = this->filesystem_.filepath_.parent_path().string();
  }
  return entry_name;
}

std::vector<std::unique_ptr<FileEntry>>
FileEntry::getEntryChildren(std::filesystem::file_type type) {
  std::vector<FileEntry> children;
  if (type == std::filesystem::file_type::directory) {
    for (auto const &dir_items : std::filesystem::recursive_directory_iterator{
             this->filesystem_.filepath_}) {
      children.push_back(std::move(FileEntry(dir_items)));
    }
    // get dir children filepaths making sure they are files and not directories
    // iterate over them and convert to file entires
  }
  return children;
}
