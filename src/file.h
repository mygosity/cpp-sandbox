#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace mgcp {

class FileHelper {
   public:
    static std::string ReadFile(const std::string& filepath) {
        std::ifstream inputfile{filepath.c_str()};
        std::string file_contents{std::istreambuf_iterator<char>(inputfile), std::istreambuf_iterator<char>()};
        return file_contents;
    }

    static void WriteFile(const std::string& filepath, const std::string& input) {
        std::ofstream file(filepath.c_str());
        file << input;
    }
};

}  // namespace mgcp