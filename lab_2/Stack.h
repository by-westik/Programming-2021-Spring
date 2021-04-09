//
// Created by User on 09.04.2021.
//
#include "Sequence.h"
#ifndef LABA_2_STACK_H
#define LABA_2_STACK_H


template <class T> class Stack {
public:
    LinkedListSequence<T> *list;
    Stack()
    :list(new LinkedListSequence<T>())
    {
    };
    Stack(const T* _list, int _size)
    :list(new LinkedListSequence<T>(_list, _size))
    {
    };
    Stack(Stack <T> &stack)
    :list(new LinkedListSequence<T>(stack.list))
    {
    };
    ~Stack(){
        delete list;
    }
    bool isEmpty(){
        if(!(this -> list -> data -> size)){
            return false;
        };
        return true;
    };
    int getSize(){
        return this -> list -> getLength();
    };
    T& top(){
        return this -> list ->  getFirst();
    };
      void printStack(){
        this -> list -> printLinkedListSequence();
    };
    void push(T item){
        this -> list -> append(item);
    };
    void pop(){
        Item <T> *ptr = this -> list -> data -> head;
        this -> list -> data -> head = this -> list -> data -> head -> next;
        delete ptr;
        this -> list -> data -> size--;
    };
};


#endif //LABA_2_STACK_H
