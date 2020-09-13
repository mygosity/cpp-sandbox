#include "main.h"

int main(int argc, char* argv[]) {
    mgcp::FileHelper fh;
    std::string inputRead = fh.ReadFile("./_logs/hr_input07.txt");
    std::cout << "size : " << inputRead.size() << '\n';

    std::vector<std::string>* list = mgcp::SplitString(inputRead, '\n');
    std::cout << "size : " << list->size() << '\n';

    std::string output;
    fh.WriteFile("./_logs/test.txt", output);

    delete list;
}