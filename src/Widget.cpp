#include <iostream>
#include "include/Widget.h"

using namespace WidgetNamespace;

Widget::Widget()
{
    std::cout << "Widget object " << std::endl;
}

void Widget::Step() const
{
    static int stepCounter = 0;
    std::cout << "Widget step " << stepCounter++ << std::endl;
}