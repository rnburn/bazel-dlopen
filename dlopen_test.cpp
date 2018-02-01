#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

int main(int argc, char* argv[]) {
  auto library =  exec("find . -name *liba*");
  library = library.substr(0, library.size()-1);
  const auto handle = dlopen(library.c_str(), RTLD_NOW | RTLD_LOCAL);
  if (handle == nullptr) {
    std::cerr << dlerror() << "\n";
    return -1;
  }
  return 0;
}
