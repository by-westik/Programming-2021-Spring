//
// Created by User on 03.04.2021.
//

#ifndef LABA_2_SEQUENCE_H
#define LABA_2_SEQUENCE_H
#include "DynamicArray.h"
#include "LinkedList.h"

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
    virtual void printSequence() = 0;
    virtual void deleteFirst() = 0;
};

template <class T> class LinkedListSequence : public Sequence <T>{
private:
    LinkedList <T> *data;
public:
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
    T& getFirst() override{
        try{
          return this -> data -> getFirst();
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
    };
    T& getLast() override{
        try{
          return this -> data -> getLast();
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
    };
    T& get(int index) override{
        try{
          return this -> data -> get(index);
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
    };
    int getLength() override{
        return this -> data -> getLength();
    };
    void append(T item) override{
        this -> data -> append(item);
    };
    void prepend(T item) override{
        this -> data -> prepend(item);
    };
    void insertAt(T item, int index) override {
        try{
            this -> data -> insertAt(item, index);
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
    };
    void printSequence() override {
        this -> data -> printList();
    };
    void getSubsequence(int startIndex,int endIndex, Sequence <T> &subSequence) override
    {
        this -> data -> getSubList(startIndex, endIndex, *(dynamic_cast <LinkedListSequence<T>&>(subSequence).data));
    };
    void concat(Sequence <T> *list, Sequence <T> &concatSequence) override {
        this -> data -> concat((dynamic_cast <LinkedListSequence<T>*>(list)) -> data, *(dynamic_cast <LinkedListSequence<T>&>(concatSequence).data));
    };
    void deleteFirst() override {
        try{
          this -> data -> getFirst();
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
        Item <T> *ptr = this -> data -> head;
        if(!(this -> data -> head -> next)) {
            this -> data -> head = this -> data -> head -> next;
        } else {
            this -> data -> head = NULL;
            this -> data -> tail = NULL;
        }
        delete ptr;
        this -> data -> size--;
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
    T& getFirst() override{
        try{
          return this -> data -> get(0);
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
    };
    T& getLast() override{
        try{
          return this -> data -> get(data -> getSize() - 1);
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
    };
    T& get(int index) override{
        try{
          return this -> data -> get(index);
        }
        catch (Error &error){
            std::cout << "Error: " << error.getError() << std::endl;
        }
    };
    void getSubsequence(int startIndex, int endIndex, Sequence <T> &subSequence) override{
        int j = 0;
        dynamic_cast <ArraySequence<T>&> (subSequence).data -> resize(endIndex - startIndex);
        for(int i = startIndex; i < endIndex; i++){
            dynamic_cast <ArraySequence<T>&> (subSequence).data -> set(j, this -> data -> get(i));
            j++;
        }
    };

    int getLength() override{
        return this -> data -> getSize();
    };
    void append(T item) override{
        this -> data -> resize(data -> getSize() + 1);
        for(int i = data -> getSize() - 1; i > 0; i--){
            this -> data -> set(i, this -> data -> get(i - 1));
        }
        this -> data -> set(0, item);
    };
    void prepend(T item) override {
        this -> data -> resize(data -> getSize() + 1);
        this -> data -> set(data -> getSize() - 1, item);
    };
    void insertAt(T item, int index) override{
        this -> data -> resize(data -> getSize() + 1);
        for(int i = this -> data -> getSize() - 1; i > index; i--){
            this -> data -> set(i, this -> data ->get(i - 1));
        }
        this -> data -> set(index, item);
    };
    void concat(Sequence <T> *list, Sequence <T> &newSequence) override{
       dynamic_cast <ArraySequence<T>&> (newSequence).data -> resize(this -> data -> getSize() + dynamic_cast <ArraySequence<T>*> (list) -> data -> getSize());
       int j = 0;
       for(j; j < this -> data -> getSize(); j++){
           dynamic_cast <ArraySequence<T>&> (newSequence).data -> set(j, (this -> data -> get(j)));
       }
       for(int i = 0; i < dynamic_cast <ArraySequence<T>*> (list) -> data -> getSize(); i++){
           dynamic_cast <ArraySequence<T>&> (newSequence).data -> set(j, (dynamic_cast <ArraySequence<T>*> (list)) -> data -> get(i));
           j++;
       }
    };
    void printSequence() override {
        this -> data -> printArray();
    };
    void deleteFirst() override {
         for(int i = 0; i < this -> data -> getSize() - 1; i++){
             this -> data -> set(i, this -> data -> get(i + 1));
         }
         this -> data -> resize(this -> data -> getSize() - 1);
    };
};


#endif //LABA_2_SEQUENCE_H

