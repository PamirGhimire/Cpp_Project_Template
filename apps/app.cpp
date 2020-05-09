#include <iostream>
#include "include/class1.h"

int main(int argc, char* argv[])
{
    std::cout << "main method in app" << std::endl;

    SomeNamespace::Class1 class1_object;
    class1_object.DoSomething();

    return EXIT_SUCCESS;
}