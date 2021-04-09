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
    :list(new LinkedListSequence<T>(*(stack.list)))
    {
    };
    ~Stack(){
        delete list;
    }
    bool isEmpty(){
        if(!(this -> list -> data -> size)){
            return true;
        };
        return false;
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
    void map(){
        Item <T> *ptr = this -> list -> data -> head;
        while(ptr){
            ptr -> data *= 2;
            ptr = ptr -> next;
        };
    };
    Stack <T>* subStack(int startIndex, int endIndex){
        Stack<T> *subStack(new Stack());
        subStack -> list = static_cast <LinkedListSequence<T>*> (this -> list ->getSubsequence(startIndex, endIndex));
        return subStack;
    }
    Stack <T>* concatStack(Stack<T> &stack){
        Stack<T> *concatStack(new Stack(*this));
        concatStack -> list = static_cast <LinkedListSequence<T>*> (this -> list -> concat(dynamic_cast<Sequence<T>*>(stack.list)));
        return concatStack;
    };
};


#endif //LABA_2_STACK_H
