#include <iostream>
#include "gtest/gtest.h"

#include "include/class1.h"

class Class1TestFixture : public ::testing::Test
{
  protected:
    virtual void SetUp()
    {
        // Code here will be called immediately after the fixture constructor (right
        // before each test).
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test (right
        // before the fixture destructor).
    }

    // Objects declared here can be used by all tests in the test case for Class1.
    SomeNamespace::Class1 c1;
};

TEST_F(Class1TestFixture, TestDoSomethingMethodInClass1)
{
    c1.DoSomething();
    EXPECT_EQ(1, 1);
}