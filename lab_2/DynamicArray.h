//
// Created by User on 01.04.2021.
//

#ifndef LAB_2_DYNAMICARRAY_H
#define LAB_2_DYNAMICARRAY_H

template <class T> class DynamicArray{
public:
    T* array;
    int size;
    DynamicArray(int _size);
    DynamicArray(const T* _array, int _size);
    DynamicArray(DynamicArray <T> const &dynamicArray);
    void printArray();
    const T& get(int index);
    void set(int index, T value);
    int getSize();
    void resize(int newSize);
};


#endif //LAB_2_DYNAMICARRAY_H
