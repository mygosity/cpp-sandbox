#include "main.h"

#include <algorithm>
#include <deque>
#include <map>
#include <vector>

using namespace std;

#define STRINGIFY(s) #s
#define TEST_ANSWER(tag, yourAnswer, theirAnswer) std::cout << tag << "\nyour: " << yourAnswer << "\nthem: " << theirAnswer << '\n';
#define PRINT_INPUT_SIZE(input) \
    std::cout << STRINGIFY(input) << " params: " << input.params.size() << " args: " << input.args.size() << '\n';

// based off of HackerRank input files
struct FileInput {
    std::vector<std::string> args;
    std::vector<std::string> params;
};

FileInput getVectorizedFileInput(const std::string& filepath) {
    std::string inputstring = mgcp::FileHelper::ReadFile(filepath);
    std::vector<std::string> inputsplit = mgcp::SplitString(inputstring, '\n');

    FileInput input;
    input.params = mgcp::SplitString(inputsplit[0], ' ');
    input.args = mgcp::SplitString(inputsplit[1], ' ');
    return input;
}

int main(int argc, char* argv[]) {
    const std::string baseFilePath = "./inputs/";
    FileInput input = getVectorizedFileInput(baseFilePath + "test01.txt");
    PRINT_INPUT_SIZE(input);
}