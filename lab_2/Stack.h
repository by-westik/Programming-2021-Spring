//
// Created by User on 09.04.2021.
//

#ifndef LABA_2_STACK_H
#define LABA_2_STACK_H
#include "Sequence.h"
#include "FunctionForMap.h"
#include "FunctionForWhere.h"

template <class T, template <class> class Sequence> class Stack {
public:
    Sequence <T> *list;
    Stack()
    :list(new Sequence <T>())
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
    virtual ~Stack(){
        delete list;
    };
    bool isEmpty(){
        if(!(this -> list -> getLength())){
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
    void map(T function(T, T), T n){
        if(isEmpty())
            throw Error(ERROR[2]);
        Sequence <T> *newList = new Sequence <T> ();
        for(int i = 0; i < this -> getSize(); i++){
            newList -> prepend(function(this -> list -> get(i), n));
        }
        delete list;
        this -> list = newList;
    };
    void where(bool function(T, T), T n){
        if(isEmpty())
            throw Error(ERROR[2]);
        Sequence <T> *newList = new Sequence <T> ();
        for(int i = 0; i < this -> getSize(); i++){
            if(function(this -> list -> get(i), n)){
                newList -> prepend(this -> list -> get(i));
            };
        };
        delete list;
        this -> list = newList;
    };
    T reduce(T function(T, T), T n){
        if(isEmpty())
            throw Error(ERROR[2]);
        T result = n;
        for(int i = 0; i < this -> getSize(); i++){
            result += function((this -> list -> get(i)), result);
        };
        return result;
    };
    void subStack(int startIndex, int endIndex, Stack <T, Sequence> &subStack){
        if((startIndex < 0) || (endIndex < 0) || (startIndex >= getSize()) || (endIndex >= getSize()) || (startIndex > endIndex))
            throw Error(ERROR[0]);
        if(this -> isEmpty())
            throw Error(ERROR[2]);
        this -> list -> getSubsequence(startIndex, endIndex, *subStack.list);
    };
    void concatStack(Stack <T, Sequence> *stack, Stack <T, Sequence> &concatStack){
        if(stack -> isEmpty())
            throw Error(ERROR[2]);
        this -> list -> concat(stack -> list, *concatStack.list);
    };
    int findSubStack(Stack <T, Sequence> *subStack){
        if(this -> isEmpty() || (subStack -> isEmpty()))
            throw Error(ERROR[2]);
        if(this -> getSize() < subStack -> getSize())
            throw Error(ERROR[4]);
        for(int i = 0; i < this -> getSize(); i++){
             int j = i, n = 0;
             while((j < this -> getSize()) && (n < subStack -> getSize()) && (this -> list -> get(j) ==  subStack -> list -> get(n))){
                 n++;
                 j++;
             };
             if(n == subStack -> getSize()){
                 return i;
             };
        };
        return -1;
    };
};

template <> void Stack<std::pair<int,int>,LinkedListSequence>::push(std::pair<int, int> item){
    if(isEmpty()){
        this -> list -> append(item);
    }else{
        std::pair<int, int> head = this -> top();
        if(item.second >= head.second){
             this -> list -> append(item);
        }else{
             this -> list -> append(std::pair<int,int> (item.first, head.second));
        }
    }
};

template <> void Stack<std::pair<int,int>,ArraySequence>::push(std::pair<int, int> item){
    if(isEmpty()){
        this -> list -> append(item);
    }else{
        std::pair<int, int> head = this -> top();
        if(item.second >= head.second){
             this -> list -> append(item);
        }else{
             this -> list -> append(std::pair<int,int> (item.first, head.second));
        }
    }
};

#endif //LABA_2_STACK_H
