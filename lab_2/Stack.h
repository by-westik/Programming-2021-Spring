
//
// Created by User on 09.04.2021.
//
#include "Sequence.h"
#ifndef LABA_2_STACK_H
#define LABA_2_STACK_H
#include "FunctionForMap.h"
#include "FunctionForWhere.h"


template <class T, template <class> class Sequence> class Stack {
public:
    Sequence <T> *list;
    Stack()
    :list(new Sequence<T>())
    {
    };
    Stack(const T* _list, int _size)
    :list(new Sequence<T>(_list, _size))
    {
    };
    Stack(Stack <T, Sequence> &stack)
    :list(new Sequence<T>(*(stack.list)))
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
        this -> list -> printSequence();
    };
    void push(T item){
        this -> list -> append(item);
    };
    void pop(){
        this -> list -> deleteFirst();
    };
    void subStack(int startIndex, int endIndex, Stack <T, Sequence> &subStack){
        this -> list -> getSubsequence(startIndex, endIndex, *subStack.list);
    }
    void concatStack(Stack <T, Sequence> *stack, Stack <T, Sequence> &concatStack){
        this -> list -> concat(stack -> list, *concatStack.list);
    };
    void map(T function(T , T), T n){
        Sequence <T> *newList = new Sequence <T> ();
        for(int i = 0; i < this -> getSize(); i++){
            newList -> prepend(function(this -> list -> get(i), n));
        }
        delete list;
        this -> list = newList;
    }
    void where(bool function(T), Stack <T, Sequence> &newStack){
        for(int i = 0; i < this -> getSize(); i++){
            if(function(this -> list -> get(i))){
                newStack.push(this -> list -> get(i));
            }
        }
    }
    //Работающий reduce)))
    T reduce(T function(T, T), T n){
        T result = n;
        for(int i = 0; i < this -> getSize(); i++){
            result += function((this -> list -> get(i)), result);
        }
        return result;
    }
    //Поиск подстека в стеке
    int findSubStack(Stack <T, Sequence> *subStack){
        for(int i = 0; i < this -> getSize(); i++){
             int j = i, n = 0;
             while((j < this -> getSize()) && (n < subStack -> getSize()) && (this -> list -> get(j) ==  subStack -> list -> get(n))){
                 n++;
                 j++;
             };
             std::cout << n << " " << subStack -> getSize() << std::endl;
             if(n == subStack -> getSize()){
                 return i;
             }
        };
    }
};


#endif //LABA_2_STACK_H
