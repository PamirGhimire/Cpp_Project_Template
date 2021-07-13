#include <iostream>
#include "include/Widget.h"

int main(int argc, char* argv[])
{
    std::cout << "main method in app" << std::endl;
    WidgetNamespace::Widget w;

    return EXIT_SUCCESS;
}