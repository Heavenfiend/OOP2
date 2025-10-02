#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "Five.h"

Five::Five() : digits{0} {}

Five::Five(const std::string& str) {
  if (str.empty()) {
    digits = {0};
    return;
  }

  for (char c : str) {
    if (c < '0' || c > '4') {
      throw std::invalid_argument("Invalid digit in Quinary number");
    }
  }

  digits.resize(str.size());
  for (size_t i = 0; i < str.size(); ++i) {
    digits[str.size() - 1 - i] = str[i] - '0';
  }
}

Five::Five(int decimal) {
  if (decimal == 0) {
    digits = {0};
    return;
  }

  if (decimal < 0) {
    throw std::invalid_argument("Negative numbers not supported");
  }

  int num = decimal;
  while (num > 0) {
    digits.push_back(num % 5);
    num /= 5;
  }

  if (digits.empty()) {
    digits = {0};
  }
}

Five Five::assign(const Five& other) const { return Five(other); }

Five Five::add(const Five& other) const { return addDirect(other); }

Five Five::subtract(const Five& other) const {
  if (less(other)) {
    return Five("0");
  }
  return subDirect(other);
}

Five Five::addDirect(const Five& other) const {
  std::vector<unsigned char> result;
  size_t maxSize = std::max(digits.size(), other.digits.size());
  unsigned char carry = 0;

  for (size_t i = 0; i < maxSize || carry; ++i) {
    unsigned char sum = carry;
    if (i < digits.size()) sum += digits[i];
    if (i < other.digits.size()) sum += other.digits[i];

    result.push_back(sum % 5);
    carry = sum / 5;
  }

  Five newNum;
  newNum.digits = result;
  return newNum;
}

Five Five::subDirect(const Five& other) const {
  std::vector<unsigned char> result;
  unsigned char borrow = 0;

  for (size_t i = 0; i < digits.size(); ++i) {
    unsigned char diff = digits[i] - borrow;
    if (i < other.digits.size()) {
      if (diff < other.digits[i]) {
        diff += 5;
        borrow = 1;
      } else {
        borrow = 0;
      }
      diff -= other.digits[i];
    } else {
      borrow = 0;
    }
    result.push_back(diff);
  }

  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }

  Five newNum;
  newNum.digits = result;
  return newNum;
}

bool Five::equals(const Five& other) const { return digits == other.digits; }

bool Five::less(const Five& other) const {
  if (digits.size() != other.digits.size()) {
    return digits.size() < other.digits.size();
  }

  for (int i = digits.size() - 1; i >= 0; --i) {
    if (digits[i] != other.digits[i]) {
      return digits[i] < other.digits[i];
    }
  }
  return false;
}

bool Five::greater(const Five& other) const {
  return !less(other) && !equals(other);
}

size_t Five::size() const { return digits.size(); }

unsigned char Five::getDigit(size_t index) const {
  if (index >= digits.size()) {
    throw std::out_of_range("Index out of range");
  }
  return digits[index];
}

std::string Five::toString() const {
  if (digits.empty()) return "0";

  std::string result;
  for (int i = digits.size() - 1; i >= 0; --i) {
    result += std::to_string(digits[i]);
  }
  return result;
}

void Five::print() const { std::cout << toString() << std::endl; }

int Five::toDecimal() const {
  int result = 0;
  int power = 1;
  for (size_t i = 0; i < digits.size(); ++i) {
    result += digits[i] * power;
    power *= 5;
  }
  return result;
}