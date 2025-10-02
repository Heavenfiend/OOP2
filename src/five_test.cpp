#include "Five.h"
#include "gtest/gtest.h"

TEST(FiveTest, ConstructFromString) {
    Five a("42");
    EXPECT_EQ(a.toDecimal(), 22);
}

TEST(FiveTest, ConstructFromDecimal) {
    Five a(22);
    EXPECT_EQ(a.toDecimal(), 22);
}

TEST(FiveTest, AddTwoNumbers) {
    Five a("42");
    Five b("34");
    Five c = a.add(b);
    EXPECT_EQ(c.toDecimal(), 41);
}

TEST(FiveTest, SubtractTwoNumbers) {
    Five a("42");
    Five b("34");
    Five c = a.subtract(b);
    EXPECT_EQ(c.toDecimal(), 3);
}

TEST(FiveTest, SubtractResultNegativeReturnsZero) {
    Five a("34");
    Five b("42");
    Five c = a.subtract(b);
    EXPECT_EQ(c.toDecimal(), 0);
}

TEST(FiveTest, LessThanComparison) {
    Five a("34");
    Five b("42");
    EXPECT_TRUE(a.less(b));
}

TEST(FiveTest, GreaterThanComparison) {
    Five a("42");
    Five b("34");
    EXPECT_TRUE(a.greater(b));
}

TEST(FiveTest, EqualComparison) {
    Five a("42");
    Five b("42");
    EXPECT_TRUE(a.equals(b));
}

TEST(FiveTest, InvalidStringThrows) {
    EXPECT_THROW(Five("125"), std::invalid_argument);
    EXPECT_THROW(Five("abc"), std::invalid_argument);
}

TEST(FiveTest, OriginalUnchangedAfterOperations) {
    Five original("123");
    std::string originalStr = original.toString();

    Five sum = original.add(Five("1"));
    Five diff = original.subtract(Five("1"));
    Five assigned = original.assign(Five("333"));

    EXPECT_EQ(original.toString(), originalStr);
    EXPECT_EQ(original.toString(), "123");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}