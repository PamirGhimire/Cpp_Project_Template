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
        std::cout << "setup " << std::endl;
        w.SetVal(testval_);
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test (right
        // before the fixture destructor).
    }

    // Objects declared here can be used by all tests in the test case for Class1.
    WidgetNamespace::Widget w;
    int testval_{10};
};

TEST_F(WidgetTestFixture, Test_WidgetStep)
{
    std::cout << "test case" << std::endl;
    w.Show();
    EXPECT_EQ(w.GetVal(), testval_);
}