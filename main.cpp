#include "FileEntry.h"
#include "src/FileSystemService/Filesystem.h"
#include <filesystem>
#include <iostream>

int main() {
  // path
  std::filesystem::path test_path =
      "/Users/roshaniruku/Downloads/Add a heading.png";

  FileEntry fe(test_path);
  std::cout << &fe << std::endl;
  return 0;
}
