//
// Created by User on 03.04.2021.
//
#include "DynamicArray.h"
#include "LinkedList.h"
#ifndef LABA_2_SEQUENCE_H
#define LABA_2_SEQUENCE_H

template <class T> class Sequence{
public:
    virtual T& getFirst() = 0;
    virtual T& getLast() = 0;
    virtual T& get(int index) = 0;
    virtual Sequence <T>* getSubsequence(int startIndex, int endIndex) = 0;
    virtual int getLength() = 0;
    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
  //  virtual void insertAt(T item, int index) = 0;
 //   virtual Sequence <T> concat(Sequence <T> *list) = 0;
};

template <class T> class ArraySequence : Sequence<T>{

public:
    DynamicArray <T> data;
    ArraySequence(const T* _array, int _size)
    :data((DynamicArray<T>(_array, _size)))
    {

    };
    ArraySequence()
    :data(DynamicArray<T>(0))
    {

    };
    ArraySequence(ArraySequence<T> &arraySequence)
    :data(DynamicArray<T>(arraySequence.data))
    {

    };
    T& getFirst() override
    {
        return this -> data.get(0);
    };
    T& getLast() override
    {
        return this -> data.get(data.size - 1);
    };
    T& get(int index) override
    {
        return this -> data.get(index);
    };
    Sequence <T>* getSubsequence(int startIndex, int endIndex) override
    {
        ArraySequence <T> subSequence(this -> data.array, endIndex - startIndex);
        int j = 0;
        for(int i = startIndex; i < endIndex; i++){
            subSequence.data.array[j] = std::move(data.array[i]);
            j++;
        }
        subSequence.printArraySequence();
        return dynamic_cast <Sequence<T>*> (&subSequence);
    };//Эта функция не работает, но я еще исправлю
    int getLength() override
    {
        return this -> data.getSize();
    };
    void append(T item) override
    {
        data.resize(data.size + 1);
        for(int i = data.size - 1; i > 0; i--){
            data.set(i, data.get(i - 1));
        }
        data.set(0, item);
    };
    void prepend(T item) override
    {
        data.resize(data.size + 1);
        data.set(data.size - 1, item);
    };
  //  void insertAt(T item, int index) override;
  //  Sequence <T> concat(Sequence <T> *list) override;
    void printArraySequence(){
        this -> data.printArray();
    };
};


#endif //LABA_2_SEQUENCE_H
