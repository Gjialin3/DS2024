#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* arr;
    size_t capacity;
    size_t size;

public:
    Vector() : capacity(10), size(0) {
        arr = new T[capacity];
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            resize();
        }
        arr[size++] = value;
    }

    void resize() {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return arr[index];
    }

    const T& operator[](size_t index) const {  // Const version for const objects
        if (index >= size) throw std::out_of_range("Index out of range");
        return arr[index];
    }

    size_t getSize() const {  // Const getter
        return size;
    }

    // Add begin() and end() methods
    T* begin() { return arr; }
    T* end() { return arr + size; }
    const T* begin() const { return arr; }
    const T* end() const { return arr + size; }

    void clear() {
        size = 0;
    }

    void unique() {
        std::sort(arr, arr + size);
        size_t uniqueSize = 1;
        for (size_t i = 1; i < size; ++i) {
            if (arr[i] != arr[uniqueSize - 1]) {
                arr[uniqueSize++] = arr[i];
            }
        }
        size = uniqueSize;
    }
};

#endif // VECTOR_H

#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }

    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    bool operator!=(const Complex& other) const {  // 添加不等于运算符
        return !(*this == other);
    }

    bool operator<(const Complex& other) const {  // 添加小于运算符
        return this->modulus() < other.modulus();  // 按模长比较
    }

    // Getter methods
    double getReal() const { return real; }
    double getImag() const { return imag; }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        return os << "(" << c.real << ", " << c.imag << ")";
    }
};

#endif // COMPLEX_H
