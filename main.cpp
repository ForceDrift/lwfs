#include "FileSystemService/Filesystem.h"
#include <cstdint>
#include <filesystem>
#include <iostream>
int main() {
  // path
  std::filesystem::path test_path =
      "/Users/roshaniruku/Downloads/Add a heading.png";

  Filesystem fs(test_path);
  return 0;
}
