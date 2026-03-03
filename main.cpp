// #include "src/FileSystemService/FileEntry.h"
// #include "src/FileSystemService/Filesystem.h"
// #include <filesystem>
// #include <iostream>
//
// int main() {
//   // path
//   std::filesystem::path test_path =
//       "/Users/roshaniruku/Downloads/Add a heading.png";
//
//   FileEntry fe(test_path);
//   std::cout << "Hello";
//   std::cout << fe << std::endl;
//   return 0;
// }
//
#include "Filesystem.h"
#include <iostream>
int main(int argc, char *argv[]) {
  Filesystem root("./");
  root.loadChildren();
  std::cout << "\n";
  root.printTree("", true);
}
