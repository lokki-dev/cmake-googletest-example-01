#include <gtest/gtest.h>

#include "../Example.hpp"
struct ExampleTests : public ::testing::Test
{
    int * x;
    int GetX() { 
        return *x;
    }
    virtual void SetUp() override {
        fprintf(stderr, "Starting up!\n");
        x = new int(42);
    }
    virtual void TearDown() override {
        fprintf(stderr, "Tearing down!\n");
        delete x;
    }
};
TEST_F(ExampleTests, MAC)
{
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + GetX() * y; 
    EXPECT_EQ(
        expectedNewSum,
        MAC(GetX(),y,sum)
    );
    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}
TEST_F(ExampleTests, Square) {
    int expectedSquare = GetX() * GetX();
    EXPECT_EQ(
        expectedSquare,
        Square(GetX())
    );
}