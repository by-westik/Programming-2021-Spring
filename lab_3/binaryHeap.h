#include <iostream>
#include "DynamicArray.h"

using namespace std;

template <class T> void swap(T *first, T *second){
    T temporary = std::move(*first);
    *first = std::move(*second);
    *second = std::move(temporary);
};

template <class T, template <class> class DynamicArray> class binaryHeap{
private:
    DynamicArray <T> *heap;
public:
    binaryHeap()
    :heap(new DynamicArray <T> (0))
    {
    };
    binaryHeap(T *_heap, int _size)
    :heap(new DynamicArray <T> (_heap, _size))
    {
       for(int i = this -> heap -> getSize() / 2; i >= 0; i--){
           this -> heapify(i);
       };
    };
    T getParent(int index) const{
        return this -> heap -> get((index - 1) / 2);
    };
    T getLeft(int index) const{
        return this -> heap -> get(index * 2 + 1);
    };
    T getRight(int index) const{
        return this -> heap -> get(index * 2 + 2);
    };
    T getMin() const{
        T minElement = this -> heap -> get((this -> heap -> getSize()) / 2);
        for(int i = (this -> heap -> getSize()) / 2; i < this -> heap -> getSize(); i++){
            if(minElement > this -> heap -> get(i)){
                minElement = this -> heap -> get(i);
            };
        };
        return minElement;
    };
    T getMax() const{
        return this -> heap -> get(0);
    };
    void heapify(int index){
        int left, right, max;
        for(;;){
            left = 2 * index + 1;
            right = 2 * index + 2;
            max = index;
            if(left < this -> heap -> getSize() &&  this -> heap -> get(left) > this -> heap -> get(max)){
                max = left;
            };

            if(right < this -> heap -> getSize() && this -> heap -> get(right) > this -> heap -> get(max)){
                max = right;
            };

            if(max == index){
                break;
            };

            swap(this -> heap -> get(index), this -> heap -> get(max));
            index = max;
        };
    };
    void insertKey(T key){
        this -> heap -> resize(this -> heap -> getSize() + 1);
        this -> heap -> set(this -> heap -> getSize() - 1, key);
        int index = this -> heap -> getSize() - 1;
        int parent = (index - 1) / 2;

        while((index > 0) && (this -> heap -> get(parent) < this -> heap -> get(index))){
            swap(this -> heap -> get(index), this -> heap -> get(parent));

            index = parent;
            parent = (index - 1) / 2;
        };
    };
    void deleteMax(){
        for(int i = 0; i < this -> heap -> getSize() - 1; i++){
            this -> heap -> set(i, this -> heap -> get(i + 1));
        };
        this -> heap -> resize(this -> heap -> getSize() - 1);
        this -> heapify(0);
    };
    void updateKey(int index, T newKey){
        if(newKey >= this -> heap -> get(index)){
            this -> heap -> set(index, newKey);
            while((index >= 1) && (this -> heap -> get(index / 2) < this -> heap -> get(index))){
                swap(this -> heap -> get(index), this -> heap -> get(index / 2));
                index = index / 2;
            };
        };
    };
    void printHeap() const {
        this -> heap -> printArray();
    };
};


