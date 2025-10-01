#ifndef FIVE_H
#define FIVE_H

#include <string>

class Five {
private:
    struct Array {
        unsigned char* data;
        size_t length;

        Array();
        Array(const size_t& n, unsigned char t = 0);
        Array(const std::string& t);
        Array(const Array& other);
        ~Array();

        size_t size() const;
        unsigned char& operator[](size_t index);
        const unsigned char& operator[](size_t index) const;
        Array& operator=(const Array& other);
    };

    Array digits;

public:
    Five();
    Five(const std::string& str);
    Five(int decimal);
    Five(const Five& other);

    Five& operator=(const Five& other);
    Five operator+(const Five& other) const;
    Five operator-(const Five& other) const;

    bool operator==(const Five& other) const;
    bool operator<(const Five& other) const;
    bool operator>(const Five& other) const;

    void print() const;
    int to_decimal() const;
};

#endif