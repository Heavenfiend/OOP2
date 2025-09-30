// main.cpp
#include "Five.h"
#include <iostream>

int main() {
    try {
        Five num1("424");  // 118
        Five num2("424");  // 114
        Five sum = num1 + num2;  // 232
        Five diff = num1 - num2;  // 4

        std::cout << "num1: "; num1.print();
        std::cout << "num2: "; num2.print();
        std::cout << "sum: "; sum.print();
        std::cout << "diff: "; diff.print();

        std::cout << "num1 == num2: " << (num1 == num2 ? "true" : "false") << std::endl;
        std::cout << "num1 < num2: " << (num1 < num2 ? "true" : "false") << std::endl;
        std::cout << "num1 > num2: " << (num1 > num2 ? "true" : "false") << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}