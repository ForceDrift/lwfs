#include "src/FileSystemService/Filesystem.h"
#include <filesystem>

int main() {
  // path
  std::filesystem::path test_path =
      "/Users/roshaniruku/Downloads/Add a heading.png";

  Filesystem fs(test_path);
  return 0;
}
