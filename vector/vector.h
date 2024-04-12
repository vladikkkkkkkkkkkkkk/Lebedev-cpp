#include <iostream>
#include <algorithm>

template <class T>
class Vector {
private:
    T* array;
    size_t capacity;
    size_t size;

public:
    Vector() : array(nullptr), capacity(0), size(0) {}

    Vector(size_t initialSize) : array(new T[initialSize]), capacity(initialSize), size(initialSize) {}

    ~Vector() {
        delete[] array;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }

            T* newArray = new T[capacity];
            std::copy(array, array + size, newArray);
            delete[] array;
            array = newArray;
        }

        array[size] = value;
        size++;
    }

    void erase(size_t index) {
        if (index >= size) {
            return;
        }

        for (size_t i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--;
    }

    void insert(size_t index, const T& value) {
        if (index > size) {
            return;
        }

        if (size >= capacity) {
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity *= 2;
            }

            T* newArray = new T[capacity];
            std::copy(array, array + index, newArray);
            newArray[index] = value;
            std::copy(array + index, array + size, newArray + index + 1);
            delete[] array;
            array = newArray;
            size++;
        }
        else {
            for (size_t i = size; i > index; i--) {
                array[i] = array[i - 1];
            }

            array[index] = value;
            size++;
        }
    }

    T& operator[](size_t index) {
        return array[index];
    }

    size_t getSize() const {
        return size;
    }

    void reserve(size_t newCapacity) {
        if (newCapacity <= capacity) {
            return;
        }

        T* newArray = new T[newCapacity];
        std::copy(array, array + size, newArray);
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

    // Implementations of getSum, getAverage, getMedian can be added here

    // Example method to print all elements
    void print() {
        for (size_t i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec.print(); // Output: 1 2 3

    vec.insert(1, 4);
    vec.print(); // Output: 1 4 2 3

    vec.erase(1);
    vec.print(); // Output: 1 2 3

    std::cout << "Size: " << vec.getSize() << std::endl;

    return 0;
}
#pragma once
