//
// Made by Egor on 01.10.25
//
#include "Five.h"
#include <iostream>

int main() {
    try {
        Five num1("433");  // 118
        Five num2("424");  // 114
        Five sum = num1.add(num2);  // 232
        Five diff = num1.sub(num2);  // 4

        std::cout << "num1: "; num1.print();
        std::cout << "num2: "; num2.print();
        std::cout << "sum: "; sum.print();
        std::cout << "diff: "; diff.print();

        std::cout << "num1 == num2: " << (num1.equals(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 < num2: " << (num1.lessThan(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 > num2: " << (num1.greaterThan(num2) ? "true" : "false") << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}