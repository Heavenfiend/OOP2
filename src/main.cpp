#include "Five.h"
#include <iostream>

int main() {
    system("chcp 65001");
    try {
        Five num1("333");
        Five num2("322");

        Five sum = num1.add(num2);
        Five diff = num1.subtract(num2);

        Five num3 = num1.assign(num2);

        std::cout << "num1: "; num1.print();
        std::cout << "num2: "; num2.print();
        std::cout << "sum = num1 + num2 = "; sum.print();
        std::cout << "diff = num1 - num2 = "; diff.print();
        std::cout << "num3 (копия): "; num3.print();

        std::cout << "num1 == num2: " << (num1.equals(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 < num2: " << (num1.less(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 > num2: " << (num1.greater(num2) ? "true" : "false") << std::endl;

        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}