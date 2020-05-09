#include <iostream>
#include "include/class1.h"
#include "library1/library1Class.h"
#include "library2/library2Class.h"

using namespace SomeNamespace;

Library1Class lib1_obj_;
Library2Class lib2_obj_;

void Class1::DoSomething()
{
    std::cout << "Class1 Object doing something, and namepsace constant : " << SomeNamespaceConstant << std::endl;
    lib1_obj_.DoSomething();
    lib2_obj_.DoSomething();
}
