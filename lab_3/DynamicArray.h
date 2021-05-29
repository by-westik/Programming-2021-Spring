#ifndef LAB_3_DYNAMICARRAY_H
#define LAB_3_DYNAMICARRAY_H
//#include "classesForStack.cpp"
#include "Error.cpp"

template <class T> class DynamicArray{
private:
    T* array;
    int size;
    int capacity;
public:
    DynamicArray(int _size)
    :size(_size)
    ,capacity(_size)
    {
      if(_size){
          array = new T[_size];
      }else{
          array = NULL;
      }
    };
    DynamicArray(const T* _array, int _size)
    :size(_size)
    ,capacity(_size)
    ,array(new T[_size])
    {
        for(int i = 0; i < _size; i++){
            array[i] = std::move(_array[i]);
        }
    };
    DynamicArray(DynamicArray <T> const &dynamicArray)
    :size(dynamicArray.size)
    ,capacity(dynamicArray.size)
    ,array(new T[dynamicArray.size])
    {
       for(int i = 0; i < dynamicArray.size; i++){
           array[i] = std::move(dynamicArray.array[i]);
       }
    };
    ~DynamicArray(){
        delete[] array;
    };
    void printArray(){
        for (int i = 0; i < size; i++)
            std::cout<< " " << array[i];
        std::cout << std::endl;
    };
    T& get(int index){
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        return array[index];
    };
    void set(int index, T &value){
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        array[index] = value;
    };
    T& operator[](int index){
        if((index < 0) || (index >= size))
            throw Error("Index out of range");
        return array[index];
    };
    int getSize(){
        return size;
    };
    void prepend(T &value){
        if((this -> getSize() + 1) >= this -> capacity){
            if(this -> getSize() == 0){
                this -> resize(1);
            };
            this -> resize((this -> capacity) * 2);
        };
        this -> array[this -> getSize()] = value;
        this -> size++;
    };
    void resize(int newSize){
        if(this -> size != 0){
            T *newArray = new T[newSize];
            if(this -> size > newSize){
                for(int i = 0; i < newSize; i++){
                    newArray[i] = std::move(array[i]);
                };
                this -> size = newSize;
            } else if(this -> size <= newSize){
                for(int i = 0; i < size; i++){
                    newArray[i] = std::move(array[i]);
                };
            };
            delete[] array;
            this -> array = newArray;
        } else {
            delete[] array;
            this -> array = new T[newSize];
            this -> size = 0;
        };
        this -> capacity = newSize;
    };
};