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
    virtual Sequence <T>* getSubsequence(int startIndex,int endIndex) = 0;
    virtual int getLength() = 0;
    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
    virtual void insertAt(T item, int index) = 0;
 //   virtual Sequence <T>* concat(Sequence <T> *list) = 0;
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
        data -> append(item);
    };
    void prepend(T item) override
    {
        data -> prepend(item);
    };
    void insertAt(T item, int index) override{
        data -> insertAt(item, index);
    };
    void printLinkedListSequence(){
        this -> data -> printList();
    };
    //Тут утечки памяти из-за new, но без него пока сделать не получается
    Sequence <T>* getSubsequence(int startIndex,int endIndex) override
    {
        LinkedListSequence<T> *subSequence(new LinkedListSequence<T>());
        delete subSequence -> data;
        subSequence -> data = this -> data -> getSubList(startIndex, endIndex);
        return dynamic_cast <Sequence<T>*> (subSequence);
    }
};

template <class T> class ArraySequence :public Sequence<T>{

public:
    DynamicArray <T> *data;
    ArraySequence(const T* _array, int _size)
    :data(new DynamicArray<T>(_array, _size))
    {
       std::cout << "ArraySequence const* Constructor" << std::endl;
    };
    ArraySequence()
    :data(new DynamicArray<T>(0))
    {

    };
    ArraySequence(ArraySequence<T> &arraySequence)
    :data(new DynamicArray<T>(*arraySequence.data))
    {
       std::cout << "ArraySequence copy Constructor" << std::endl;
    };
    ~ArraySequence(){
      std::cout << "ArraySequence Destructor" << std::endl;
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
    //Тут тоже утечки памяти из-за new
    Sequence <T>* getSubsequence(int startIndex,int endIndex) override
    {
        ArraySequence <T> *subSequence(new ArraySequence <T> ());
        int j = 0;
        subSequence -> data -> resize(endIndex - startIndex);
        for(int i = startIndex; i < endIndex; i++){
            subSequence -> data -> set(j, this -> data -> array[i]);
            j++;
        }
        return dynamic_cast <Sequence<T>*> (subSequence);
    };

    int getLength() override
    {
        return this -> data -> getSize();
    };
    void append(T item) override
    {
        data -> resize(data -> size + 1);
        for(int i = data -> size - 1; i > 0; i--){
            data -> set(i, data -> get(i - 1));
        }
        data -> set(0, item);
    };
    void prepend(T item) override
    {
        data -> resize(data -> size + 1);
        data -> set(data -> size - 1, item);
    };
    void insertAt(T item, int index) override{
        data -> resize(data -> size + 1);
        for(int i = data -> size - 1; i > index; i--){
            data -> set(i, data ->get(i - 1));
        }
        data -> set(index, item);
    };
    /*Sequence <T>* concat(Sequence <T> *list) override{

    };*/
    void printArraySequence(){
        this -> data -> printArray();
    };
};


#endif //LABA_2_SEQUENCE_H

