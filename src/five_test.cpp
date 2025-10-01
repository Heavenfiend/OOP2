#include "gtest/gtest.h"
#include "Five.h"
#include <string>

TEST(FiveTest, DefaultConstructor) {
    Five num;
    EXPECT_EQ(num.to_decimal(), 0);
}

TEST(FiveTest, StringConstructor) {
    Five num("42");
    EXPECT_EQ(num.to_decimal(), 22);
}

TEST(FiveTest, DecimalConstructor) {
    Five num(22);
    EXPECT_EQ(num.to_decimal(), 22);
}

TEST(FiveTest, Addition) {
    Five a("42");
    Five b("34");
    Five c = a + b;
    EXPECT_EQ(c.to_decimal(), 41);
}

TEST(FiveTest, Subtraction) {
    Five a("42");
    Five b("34");
    Five c = a - b;
    EXPECT_EQ(c.to_decimal(), 3);
}

TEST(FiveTest, SubtractionNegative) {
    Five a("34");
    Five b("42");
    Five c = a - b;
    EXPECT_EQ(c.to_decimal(), 0);
}

TEST(FiveTest, Equality) {
    Five a("42");
    Five b("42");
    EXPECT_TRUE(a == b);
}

TEST(FiveTest, LessThan) {
    Five a("34");
    Five b("42");
    EXPECT_TRUE(a < b);
}

TEST(FiveTest, GreaterThan) {
    Five a("42");
    Five b("34");
    EXPECT_TRUE(a > b);
}

TEST(FiveTest, InvalidStringThrows) {
    EXPECT_THROW(Five("125"), std::invalid_argument);
    EXPECT_THROW(Five("abc"), std::invalid_argument);
}

TEST(FiveTest, CopyConstructor) {
    Five a("42");
    Five b(a);
    EXPECT_EQ(a.to_decimal(), b.to_decimal());
}

TEST(FiveTest, Assignment) {
    Five a("42");
    Five b;
    b = a;
    EXPECT_EQ(a.to_decimal(), b.to_decimal());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}