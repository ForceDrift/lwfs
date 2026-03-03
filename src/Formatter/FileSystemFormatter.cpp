#include <chrono>
#include <cstdint>
#include <filesystem>
#include <format>
#include <iostream>
#include <string>
std::string getPathString(std::filesystem::path path) {
  return path.generic_string();
}
std::string getSizeString(uintmax_t size) { return std::to_string(size); }

std::string getFileType(std::filesystem::file_status s) {
  switch (s.type()) {
  case std::filesystem::file_type::none:
    return "none";
    break;
  case std::filesystem::file_type::not_found:
    return "not_found";
    break;
  case std::filesystem::file_type::regular:
    return "regular";
    break;
  case std::filesystem::file_type::directory:
    return "directory";
    break;
  case std::filesystem::file_type::symlink:
    return "symlink";
    break;
  case std::filesystem::file_type::block:
    return "block";
    break;
  case std::filesystem::file_type::character:
    return "character";
    break;
  case std::filesystem::file_type::fifo:
    return "fifo";
    break;
  case std::filesystem::file_type::socket:
    return "socket";
    break;
  case std::filesystem::file_type::unknown:
    return "unknown";
    break;
  default:
    std::cout << " has `implementation-defined` type";
    break;
  }
  return " ";
}
std::string getTimeString(std::filesystem::file_time_type time) {
  auto systemTime = std::chrono::file_clock::to_sys(time);

  return std::format("File write time is {}\n", systemTime);
}
