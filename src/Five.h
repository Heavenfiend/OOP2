#ifndef FIVE_H
#define FIVE_H

#include <string>
#include <vector>
#include <stdexcept>

class Five {
private:
    std::vector<unsigned char> digits;

    Five addDirect(const Five& other) const;
    Five subDirect(const Five& other) const;

public:
    Five() : digits{0} {}
    Five(const std::string& str);
    Five(int decimal);
    Five(const Five& other) = default;

    Five& operator=(const Five& other) = default;

    Five add(const Five& other) const;
    Five subtract(const Five& other) const;

    bool equals(const Five& other) const;
    bool less(const Five& other) const;
    bool greater(const Five& other) const;

    size_t size() const;
    unsigned char getDigit(size_t index) const;
    Five assign(const Five& other) const;

    std::string toString() const;
    void print() const;
    int toDecimal() const;
};

#endif
