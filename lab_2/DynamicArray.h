//
// Created by User on 03.04.2021.
//

#ifndef LABA_2_DYNAMICARRAY_H
#define LABA_2_DYNAMICARRAY_H
#include "classesForStack.h"

template <class T> class DynamicArray{
public:
    T* array;
    int size;
    DynamicArray(int _size)
    :size(_size)
    {
      if(_size){
          array = new T[_size];
      }else{
          array = NULL;
      }
    };
    DynamicArray(const T* _array, int _size)
    :size(_size)
    ,array(new T[_size])
    {
        for(int i = 0; i < _size; i++){
            array[i] = std::move(_array[i]);
        }
    };
    DynamicArray(DynamicArray <T> const &dynamicArray)
    :size(dynamicArray.size)
    ,array(new T[dynamicArray.size])
    {
       for(int i = 0; i < dynamicArray.size; i++){
           array[i] = std::move(dynamicArray.array[i]);
       }
    };
    ~DynamicArray(){
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
        if(this -> size != 0){
            T *newArray = new T[newSize];
            if(this -> size > newSize){
                for(int i = 0; i < newSize; i++){
                    newArray[i] = std::move(array[i]);
                }
            } else if(this -> size <= newSize){
                for(int i = 0; i < size; i++){
                    newArray[i] = std::move(array[i]);
                }
            }
            delete[] array;
            this -> array = newArray;
        } else {
            this -> array = new T[newSize];
        }
        size = newSize;
    }
};

template <> void DynamicArray<Student>::printArray(){
    for (int i = 0; i < size; i++)
        array[i].printStudent();
}
#endif //LABA_2_DYNAMICARRAY_H
