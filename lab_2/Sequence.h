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
    virtual void getSubsequence(int startIndex, int endIndex, Sequence <T> &subSequence) = 0;
    virtual int getLength() = 0;
    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
    virtual void insertAt(T item, int index) = 0;
    virtual void concat(Sequence <T> *list, Sequence <T> &newSubsequence) = 0;
};

template <class T> class LinkedListSequence : public Sequence <T>{
public:
    LinkedList <T> *data;
    LinkedListSequence(const T* _list, int _size)
    :data(new LinkedList<T>(_list, _size))
    {

    };
    LinkedListSequence()
    :data(new LinkedList<T>())
    {

    };
    LinkedListSequence(LinkedListSequence <T> &listSequence)
    :data(new LinkedList<T>(*listSequence.data))
    {

    };
    ~LinkedListSequence(){
        delete data;
    }
    T& getFirst() override
    {
        return this -> data -> getFirst();
    };
    T& getLast() override
    {
        return this -> data -> getLast();
    };
    T& get(int index) override
    {
        return this -> data -> get(index);
    };
    int getLength() override
    {
        return this -> data -> getLength();
    };
    void append(T item) override
    {
        this -> data -> append(item);
    };
    void prepend(T item) override
    {
        this -> data -> prepend(item);
    };
    void insertAt(T item, int index) override{
        this -> data -> insertAt(item, index);
    };
    void printLinkedListSequence(){
        this -> data -> printList();
    };
    void getSubsequence(int startIndex,int endIndex, Sequence <T> &subSequence) override
    {
        this -> data -> getSubList(startIndex, endIndex, *(dynamic_cast <LinkedListSequence<T>&>(subSequence).data));
    };
    void concat(Sequence <T> *list, Sequence <T> &concatSequence) override
    {
        this -> data -> concat((dynamic_cast <LinkedListSequence<T>*>(list)) -> data, *(dynamic_cast <LinkedListSequence<T>&>(concatSequence).data));
    };
};

template <class T> class ArraySequence :public Sequence<T>{
public:
    DynamicArray <T> *data;
    ArraySequence(const T* _array, int _size)
    :data(new DynamicArray<T>(_array, _size))
    {

    };
    ArraySequence()
    :data(new DynamicArray<T>(0))
    {
    };
        ArraySequence(ArraySequence<T> &arraySequence)
    :data(new DynamicArray<T>(*arraySequence.data))
    {
    };
    ~ArraySequence(){
      delete data;
    };
    T& getFirst() override
    {
        return this -> data -> get(0);
    };
    T& getLast() override
    {
        return this -> data -> get(data -> size - 1);
    };
    T& get(int index) override
    {
        return this -> data -> get(index);
    };
    void getSubsequence(int startIndex, int endIndex, Sequence <T> &subSequence) override
    {
        int j = 0;
        dynamic_cast <ArraySequence<T>&> (subSequence).data -> resize(endIndex - startIndex);
        for(int i = startIndex; i < endIndex; i++){
            dynamic_cast <ArraySequence<T>&> (subSequence).data -> set(j, this -> data -> array[i]);
            j++;
        }
    };

    int getLength() override
    {
        return this -> data -> getSize();
    };
    void append(T item) override
    {
        this -> data -> resize(data -> size + 1);
        for(int i = data -> size - 1; i > 0; i--){
            this -> data -> set(i, this -> data -> get(i - 1));
        }
        this -> data -> set(0, item);
    };
    void prepend(T item) override
    {
        this -> data -> resize(data -> size + 1);
        this -> data -> set(data -> size - 1, item);
    };
    void insertAt(T item, int index) override
    {
        this -> data -> resize(data -> size + 1);
        for(int i = this -> data -> size - 1; i > index; i--){
            this -> data -> set(i, this -> data ->get(i - 1));
        }
        this -> data -> set(index, item);
    };
    void concat(Sequence <T> *list, Sequence <T> &newSequence) override
    {
       dynamic_cast <ArraySequence<T>&> (newSequence).data -> resize(this -> data -> size + dynamic_cast <ArraySequence<T>*> (list) -> data -> size);
       int j = 0;
       for(j; j < this -> data -> size; j++){
           dynamic_cast <ArraySequence<T>&> (newSequence).data -> set(j, (this -> data -> get(j)));
       }
       for(int i = 0; i < dynamic_cast <ArraySequence<T>*> (list) -> data -> size; i++){
           dynamic_cast <ArraySequence<T>&> (newSequence).data -> set(j, (dynamic_cast <ArraySequence<T>*> (list)) -> data -> get(i));
           j++;
       }
    };
    void printArraySequence(){
        this -> data -> printArray();
    };
};


#endif //LABA_2_SEQUENCE_H
