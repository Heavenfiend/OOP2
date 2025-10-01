//
// Made by Egor on 01.10.25
//

#ifndef FIVE_H
#define FIVE_H

#include <string>

class Five {
private:
    struct Array {
        unsigned char* data;
        int length;

        Array();
        Array(int n, unsigned char t = 0);
        Array(const std::string& t);
        Array(const Array& other);
        ~Array();

        int size() const;
        unsigned char& operator[](int index);
        const unsigned char& operator[](int index) const;
        Array& operator=(const Array& other);
    };

    Array digits;

public:
    Five();
    Five(const std::string& str);
    Five(int decimal);
    Five(const Five& other);

    Five& operator=(const Five& other);

    Five add(const Five& other) const;
    Five sub(const Five& other) const;

    bool equals(const Five& other) const;
    bool lessThan(const Five& other) const;
    bool greaterThan(const Five& other) const;

    void print() const;
    int toDecimal() const;
};

#endif