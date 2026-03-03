#pragma once
#include <filesystem>
#include <string>

// class FileEntry;
std::string getPathString(std::filesystem::path path);
std::string getSizeString(uintmax_t size);
std::string getFileType(std::filesystem::file_status s);
std::string getTimeString(std::filesystem::file_time_type time);
