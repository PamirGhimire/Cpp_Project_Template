#include <iostream>
#include "include/Widget.h"

using namespace WidgetNamespace;

Widget::Widget()
{
    std::cout << "Widget constructor " << std::endl;
}

void Widget::Step() const
{
    static int stepCounter = 0;
    std::cout << "Widget step " << stepCounter++ << std::endl;
}

void Widget::SetVal(const int val)
{
    std::cout << "Widget setval" << std::endl;
    val_ = val;
}

int Widget::GetVal() const
{
    return val_;
}


void Widget::Show() const
{
    std::cout << "widget val = " << val_ << std::endl;
}
