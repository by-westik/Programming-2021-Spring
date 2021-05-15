//
// Created by User on 09.04.2021.
//
#include "Sequence.h"
#ifndef LABA_2_LINEAR_SHAPE_H
#define LABA_2_LINEAR_SHAPE_H

template <class T, template <class> class Sequence> class LinearShape {
public:
    Sequence <T> *list;
    LinearShape()
    :list(new Sequence<T>())
    {
    };
    LinearShape(const T* _list, int _size)
    :list(new Sequence<T>(_list, _size))
    {
    };
    LinearShape(LinearShape <T, Sequence> &linearShape)
    :list(new Sequence<T>(*(linearShape.list)))
    {
    };
    virtual ~LinearShape(){
        delete list;
    };
    void addRatio(T ratio){
        this -> list -> prepend(ratio);
    };
    int getSize(){
        return this -> list -> getLength();
    };
    T& getRatio(int index){
        return this -> list -> get(index);
    }
    void changeRatio(T function(T, T), T number){
        Sequence <T> *newList = new Sequence <T> ();
        for(int i = 0; i < this -> getSize(); i++){
            newList -> prepend(function(this -> getRatio(i), number));
        }
        delete list;
        this -> list = newList;
    };
    void printLinearShape(){
        int i = 0;
        for(i; i < this -> getSize() - 1; i++){
            std::cout << "(" << this -> getRatio(i) << ")" << "x" << i << "+" ;
        };
        std::cout << "(" << this -> getRatio(i) << ")" << "x" << i;
        std::cout << std::endl;
    };
    T solve(){
        T solution = this -> getRatio(0) - this -> getRatio(0);
        for(int i = 0; i < this -> getSize(); i++){
            std::cout << "Введите значение x" << i << std::endl;
            T n;
            cin >> n;
            solution += (this -> getRatio(i)) * n;
        };
        return solution;
    }
};

#endif //LABA_2_LINEAR_SHAPE_H

