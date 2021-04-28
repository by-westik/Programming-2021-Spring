//
// Created by User on 03.04.2021.
//

#ifndef LABA_2_DYNAMICARRAY_H
#define LABA_2_DYNAMICARRAY_H
#include "classesForStack.h"

class Error{
private:
    std::string error;
public:
    Error(std::string _error)
    :error(std::move(_error))
    {
    }
    std::string getError(){
        return error.c_str();
    }
};


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
    T& get(int index){
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        return array[index];
    }
    void set(int index, T &value){
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        array[index] = value;
    }
    T& operator[](int index){
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        return array[index];
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

template <> void DynamicArray<Teacher>::printArray(){
    for (int i = 0; i < size; i++)
        array[i].printTeacher();
}

template <> void DynamicArray<Complex>::printArray(){
    for (int i = 0; i < size; i++)
        array[i].printComplex();
}
#endif //LABA_2_DYNAMICARRAY_H
