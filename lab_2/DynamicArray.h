//
// Created by User on 03.04.2021.
//

#ifndef LABA_2_DYNAMICARRAY_H
#define LABA_2_DYNAMICARRAY_H
#include "classesForStack.h"
//#include "ClassError.h"
/* Это была очень неудачная попытка сделать обработку ошибок (＃￣ω￣) не буду больше такое делать(
template <class T> class Error{
private:
    bool isOK;
    T *result;
public:
    Error(){};
    Error(bool _isOK, T *_result)
    :isOK(_isOK)
    ,result(std::move(_result))
    {
    };
    bool getOK(){
        return isOK;
    }
    T &getResult(){
        return *result;
    }
    bool setOK(bool _isOK){
        isOK = _isOK;
    }
    T &setResult(T &_result){
        result = std::move(_result);
    }
};
*/

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
    /*  Error<T> get(int index)
    {
        if((index >= getSize()) || (index < 0)){
            return Error <T> (false, NULL);
        }
        return Error <T> (true, &(array[index]));
    };
    Error<T> &set(int index, T &value)
    {
        if((index >= getSize()) || (index < 0)){
            return Error <T> (false, NULL);
        }
        array[index] = value;
    }*/
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
//Можно ли как-то сделать так, чтоб передавать родительский класс Person, а методы бы вызывались от Student или Teacher?
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
