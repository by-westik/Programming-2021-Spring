//
// Created by User on 03.04.2021.
//

#ifndef LABA_2_DYNAMICARRAY_H
#define LABA_2_DYNAMICARRAY_H

template <class T> class DynamicArray{
public:
    T* array;
    int size;
    DynamicArray(int _size)
    :size(_size)
    ,array(new T[_size])
    {
    };
    DynamicArray(const T* _array, int _size)
    :size(_size)
    ,array(new T[_size])
    {
        for(int i = 0; i < _size; i++){
            array[i] = std::move(_array[i]);
        }
       std::cout << "DynamicArray const* Constructor" << std::endl;
    };
    DynamicArray(DynamicArray <T> const &dynamicArray)
    :size(dynamicArray.size)
    ,array(new T[dynamicArray.size])
    {
       for(int i = 0; i < dynamicArray.size; i++){
           array[i] = std::move(dynamicArray.array[i]);
       }
       std::cout << "DynamicArray copy Constructor" << std::endl;
    };
    ~DynamicArray(){
        std::cout << "DynamicArray destructor" << std::endl;
        delete[] array;
    };
    void printArray()
    {
        for (int i = 0; i < size; i++)
            std::cout<< " " << array[i];
        std::cout << std::endl;
    };
    T& get(int index)
    {
        return array[index];
    };
    void set(int index, T &value)
    {
        array[index] = value;
    }
    int getSize()
    {
        return size;
    }
    void resize(int newSize)
    {
        T *newArray = new T[newSize];
        if(size > newSize){
             for(int i = 0; i < newSize; i++){
                newArray[i] = std::move(array[i]);
             }
        } else if(size <= newSize){
            for(int i = 0; i < size; i++){
                newArray[i] = std::move(array[i]);
            }
        }
        delete[] array;
        this -> array = newArray;
        size = newSize;
    }
};

#endif //LABA_2_DYNAMICARRAY_H
