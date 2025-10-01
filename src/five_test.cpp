#include "Five.h"
#include "gtest/gtest.h"

TEST(FiveBasics, ConstructFromString) {
    Five a("42");
    EXPECT_EQ(a.toDecimal(), 22);
}

TEST(FiveBasics, ConstructFromDecimal) {
    Five a(22);
    EXPECT_EQ(a.toDecimal(), 22);
}

TEST(FiveArithmetic, Add) {
    Five a("42");
    Five b("34");
    Five c = a.add(b);
    EXPECT_EQ(c.toDecimal(), 41);
}

TEST(FiveArithmetic, Sub) {
    Five a("42");
    Five b("34");
    Five c = a.sub(b);
    EXPECT_EQ(c.toDecimal(), 3);
}

TEST(FiveArithmetic, SubNegative) {
    Five a("34");
    Five b("42");
    Five c = a.sub(b);
    EXPECT_EQ(c.toDecimal(), 0);
}

TEST(FiveCompare, LessThan) {
    Five a("34");
    Five b("42");
    EXPECT_TRUE(a.lessThan(b));
}

TEST(FiveCompare, GreaterThan) {
    Five a("42");
    Five b("34");
    EXPECT_TRUE(a.greaterThan(b));
}

TEST(FiveCompare, Equals) {
    Five a("42");
    Five b("42");
    EXPECT_TRUE(a.equals(b));
}

TEST(FiveErrors, InvalidString) {
    EXPECT_THROW(Five("125"), std::invalid_argument);
    EXPECT_THROW(Five("abc"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}