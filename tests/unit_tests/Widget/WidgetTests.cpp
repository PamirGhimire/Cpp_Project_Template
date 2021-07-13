#include <iostream>
#include "gtest/gtest.h"

#include "include/Widget.h"

class WidgetTestFixture : public ::testing::Test
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
    WidgetNamespace::Widget w;
};

TEST_F(WidgetTestFixture, Test_WidgetStep)
{
    for (int i = 0; i < 5; ++i)
        w.Step();
    EXPECT_EQ(1, 1);
}