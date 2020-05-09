#include <iostream>
#include "tool.h"

int main(int argc, char* argv[])
{
    std::cout << "Tool executable" << std::endl;

    Tool tool;
    tool.Tool_function();
    return EXIT_SUCCESS;
}