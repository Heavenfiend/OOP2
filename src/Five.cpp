#include "Five.h"
#include <iostream>

// Array implementation
Five::Array::Array() {
    data = 0;
    length = 0;
}

Five::Array::Array(int n, unsigned char t) {
    length = n;
    if (n <= 0) {
        data = 0;
        return;
    }
    data = new unsigned char[n];
    for (int i = 0; i < n; i++) {
        data[i] = t;
    }
}

Five::Array::Array(const std::string& t) {
    length = t.size();
    if (length == 0) {
        data = 0;
        return;
    }
    data = new unsigned char[length];
    for (int i = 0; i < length; i++) {
        if (t[i] < '0' || t[i] > '4') {
            delete[] data;
            throw std::invalid_argument("Invalid digit in string");
        }
        data[i] = t[t.size() - 1 - i] - '0';
    }
}

Five::Array::Array(const Array& other) {
    length = other.length;
    if (length == 0) {
        data = 0;
        return;
    }
    data = new unsigned char[length];
    for (int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

Five::Array::~Array() {
    if (data != 0) {
        delete[] data;
    }
}

int Five::Array::size() const {
    return length;
}

unsigned char& Five::Array::operator[](int index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const unsigned char& Five::Array::operator[](int index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

Five::Array& Five::Array::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }
    if (data != 0) {
        delete[] data;
    }
    length = other.length;
    if (length == 0) {
        data = 0;
    } else {
        data = new unsigned char[length];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Five implementation
Five::Five() {
    digits = Array(1, 0);
}

Five::Five(const std::string& str) {
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c < '0' || c > '4') {
            throw std::invalid_argument("Invalid digit in string");
        }
    }
    digits = Array(str.size());
    for (int i = 0; i < str.size(); i++) {
        digits[i] = str[str.size() - 1 - i] - '0';
    }
}

Five::Five(int decimal) {
    if (decimal == 0) {
        digits = Array(1, 0);
        return;
    }
    std::string temp = "";
    int num = decimal;
    while (num > 0) {
        temp += (num % 5) + '0';
        num = num / 5;
    }
    digits = Array(temp.length());
    for (int i = 0; i < temp.length(); i++) {
        digits[i] = temp[i] - '0';
    }
}

Five::Five(const Five& other) {
    digits = other.digits;
}

Five& Five::operator=(const Five& other) {
    if (this == &other) {
        return *this;
    }
    digits = other.digits;
    return *this;
}

Five Five::add(const Five& other) const {
    int a = toDecimal();
    int b = other.toDecimal();
    return Five(a + b);
}

Five Five::sub(const Five& other) const {
    int a = toDecimal();
    int b = other.toDecimal();
    if (b > a) {
        return Five(0);
    }
    return Five(a - b);
}

bool Five::equals(const Five& other) const {
    if (digits.size() != other.digits.size()) {
        return false;
    }
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }
    return true;
}

bool Five::lessThan(const Five& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

bool Five::greaterThan(const Five& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() > other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != other.digits[i]) {
            return digits[i] > other.digits[i];
        }
    }
    return false;
}

void Five::print() const {
    for (int i = digits.size() - 1; i >= 0; i--) {
        std::cout << (int)digits[i];
    }
    std::cout << std::endl;
}

int Five::toDecimal() const {
    int result = 0;
    int power = 1;
    for (int i = 0; i < digits.size(); i++) {
        result += digits[i] * power;
        power = power * 5;
    }
    return result;
}