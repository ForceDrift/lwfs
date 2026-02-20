#pragma once
// #include "../FileSystemService/FileEntry.h"
#include <filesystem>
#include <string>

std::string getPathString(std::filesystem::path path);
std::string getSizeString(uintmax_t size);
std::string getFileType(std::filesystem::file_status s);
std::string getTimeString(std::filesystem::file_time_type time);
// std::string getStringChildren(std::vector<FileEntry> &a);
