#include "gtest/gtest.h"
#include "Five.h"
#include <string>

// Тест конструктора по умолчанию
TEST(FiveTest, DefaultConstructor) {
    Five num;
    EXPECT_EQ(num.to_decimal(), 0);
}

// Тест конструктора из строки
TEST(FiveTest, StringConstructor) {
    Five num("42");
    EXPECT_EQ(num.to_decimal(), 22);  // 2*1 + 4*5 = 22
}

// Тест конструктора из десятичного числа
TEST(FiveTest, DecimalConstructor) {
    Five num(22);
    EXPECT_EQ(num.to_decimal(), 22);
}

// Тест сложения
TEST(FiveTest, Addition) {
    Five a("42");  // 22
    Five b("34");  // 19
    Five c = a + b;  // 41
    EXPECT_EQ(c.to_decimal(), 41);
}

// Тест вычитания
TEST(FiveTest, Subtraction) {
    Five a("42");  // 22
    Five b("34");  // 19
    Five c = a - b;  // 3
    EXPECT_EQ(c.to_decimal(), 3);
}

// Тест вычитания, когда результат < 0
TEST(FiveTest, SubtractionNegative) {
    Five a("34");  // 19
    Five b("42");  // 22
    Five c = a - b;  // 0
    EXPECT_EQ(c.to_decimal(), 0);
}

// Тест сравнения ==
TEST(FiveTest, Equality) {
    Five a("42");
    Five b("42");
    EXPECT_TRUE(a == b);
}

// Тест сравнения <
TEST(FiveTest, LessThan) {
    Five a("34");  // 19
    Five b("42");  // 22
    EXPECT_TRUE(a < b);
}

// Тест сравнения >
TEST(FiveTest, GreaterThan) {
    Five a("42");  // 22
    Five b("34");  // 19
    EXPECT_TRUE(a > b);
}

// Тест на валидацию строки
TEST(FiveTest, InvalidStringThrows) {
    EXPECT_THROW(Five("125"), std::invalid_argument);
    EXPECT_THROW(Five("abc"), std::invalid_argument);
}

// Тест на копирование
TEST(FiveTest, CopyConstructor) {
    Five a("42");
    Five b(a);
    EXPECT_EQ(a.to_decimal(), b.to_decimal());
}

// Тест на присваивание
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