#pragma once

#include <cstddef>
#include <array>
#include <iostream>

class Row_Or_Line
{ 
public:
    Row_Or_Line(); // конструктор по умолчанию
    Row_Or_Line(size_t len); // конструктор длины
    Row_Or_Line(const Row_Or_Line& other);//

    int size() const;
    void resize(size_t len);
    void setElement(size_t index, double value1, double value2);
    std::array<double, 2> multiply(const Row_Or_Line& other) const;

    virtual ~Row_Or_Line() noexcept;

public:
    double**_array;
    size_t _length;
};