#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace mgcp {

class FileHelper {
   public:
    FileHelper(){};
    ~FileHelper(){};

    std::string ReadFile(const std::string& filepath) {
        std::ifstream inputfile{filepath.c_str()};
        std::string file_contents{std::istreambuf_iterator<char>(inputfile), std::istreambuf_iterator<char>()};
        // std::ifstream file(filepath.c_str());
        // std::stringstream buffer;
        // buffer << file.rdbuf();
        // std::string file_contents = buffer.str();
        // std::cout << file_contents;
        return file_contents;
    }

    void WriteFile(const std::string& filepath, const std::string& input) {
        std::ofstream file(filepath.c_str());
        file << input;
    }
};

}  // namespace mgcp