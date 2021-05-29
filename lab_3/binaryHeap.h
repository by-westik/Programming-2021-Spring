#include <iostream>
#include "DynamicArray.h"
#include <vector>
#include <algorithm>

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
    binaryHeap(binaryHeap <T, DynamicArray> *_heap)
    :heap(new DynamicArray <T> (_heap -> heap))
    {
    };
    ~binaryHeap(){
        delete heap;
    };
    T& get(int index) const{
        return this -> heap -> get(index);
    };
    T& getParent(int index) const{
        return this -> heap -> get((index - 1) / 2);
    };
    T& getLeft(int index) const{
        return this -> heap -> get(index * 2 + 1);
    };
    T& getRight(int index) const{
        return this -> heap -> get(index * 2 + 2);
    };
    T& getMin() const{
        T minElement = this -> heap -> get((this -> heap -> getSize()) / 2);
        for(int i = (this -> heap -> getSize()) / 2; i < this -> heap -> getSize(); i++){
            if(minElement > this -> heap -> get(i)){
                minElement = this -> heap -> get(i);
            };
        };
        return minElement;
    };
    T& getMax() const{
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
        this -> heap -> prepend(key);
        int index = this -> heap -> getSize() - 1;
        int parent = (index - 1) / 2;
        while((index > 0) && (this -> heap -> get(parent) < this -> heap -> get(index))){
            swap(this -> heap -> get(index), this -> heap -> get(parent));

            index = parent;
            parent = (index - 1) / 2;
        };
    };
    void deleteMax(){
        this -> heap -> set(0, this -> heap -> get(this -> heap -> getSize() - 1));
        this -> heap -> resize(this -> heap -> getSize() - 1);
        this -> heapify(0);
    };
    void updateKey(int index, T &newKey){
        if(newKey < this -> heap -> get(index))
            throw Error("NewKey is smaller than OldKey");
        if((index < 0) || (index >= this -> heap -> getSize()))
            throw Error("Index out of range");
        this -> heap -> set(index, newKey);
        while((index >= 1) && (this -> heap -> get(index / 2) < this -> heap -> get(index))){
            swap(this -> heap -> get(index), this -> heap -> get(index / 2));
            index = index / 2;
        };
    };
    int findKey(T _key){
        for(int i = 0; i < this -> heap -> getSize(); i++){
            if(this -> heap -> get(i) == _key){
                return i;
            };
        };
        return -1;
    };
    void getSubHeap(int index, binaryHeap <T, DynamicArray> &_heap) const{
        if((index < 0) || (index >= this -> heap -> getSize()))
            throw Error("Index out of range");
        vector <int> indexes;
        indexes.push_back(index);
        int n_l = index, n_r = index, i = 1, size = this -> heap -> getSize();
        while((this -> heap -> getSize() > n_l) && (this -> heap -> getSize() > n_r)){
            n_l = n_l * 2 + 1;
            indexes.push_back(n_l);
            i++;
            n_r = n_r * 2 + 2;
            indexes.push_back(n_r);
            i++;
        };
        i-=2;
        indexes.resize(i);
        for(int j = 0; j < i; j++){
            indexes.push_back(indexes[j] * 2 + 1);
            indexes.push_back(indexes[j] * 2 + 2);
        };
        sort(indexes.begin(), indexes.end());
        indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());
        indexes.erase(std::remove_if(indexes.begin(), indexes.end(), [size] (int x) {return x >= size;}), indexes.end());
        for(int j = 0; j < indexes.size(); j++){
            _heap.heap -> prepend(this -> heap -> get(indexes[j]));
        };
    };
    void heapSort(T *_array, int size){
        binaryHeap <T, DynamicArray> *temp = new binaryHeap <T, DynamicArray> (_array, size);
        for(int i = size - 1; i >= 0; i--){
            _array[i] = temp -> getMax();
            temp -> deleteMax();
            temp -> heapify(0);
        };
        delete temp;
    };
    void printHeap() const {
        this -> heap -> printArray();
    };
    void printKLP(int index) const {
        try{
            cout << this -> heap -> get(index) << " ";
            printKLP((index * 2) + 1);
            printKLP((index * 2) + 2);
        } catch (Error &error){
            return;
        };
    };
    void printKPL(int index) const {
        try{
            cout << this -> heap -> get(index) << " ";
            printKPL((index * 2) + 2);
            printKPL((index * 2) + 1);
        } catch (Error &error){
            return;
        };
    };
    void printLPK(int index) const {
        try{
            this -> heap -> get(index);
            printLPK((index * 2) + 1);
            cout << this -> getLeft(index) << " ";
            printLPK((index * 2) + 2);
            cout << this -> getRight(index) << " ";
            if(!index){
                cout << this -> heap -> get(index) << " ";
            };
        } catch (Error &error){
            return;
        };
    };
    void printLKP(int index) const{
        try{
            this -> heap -> get(index);
            printLKP((index * 2) + 1);
            cout << this -> heap -> get(index) << " ";
            printLKP((index * 2) + 2);
        } catch (Error &error){
            return;
        };
    };
    void printPLK(int index) const {
        try{
            this -> heap -> get(index);
            printLPK((index * 2) + 2);
            cout << this -> getRight(index) << " ";
            printLPK((index * 2) + 1);
            cout << this -> getLeft(index) << " ";
            if(!index){
                cout << this -> heap -> get(index) << " ";
            };
        } catch (Error &error){
            return;
        };
    };
    void printPKL(int index) const{
        try{
            this -> heap -> get(index);
            printPKL((index * 2) + 2);
            cout << this -> heap -> get(index) << " ";
            printPKL((index * 2) + 1);
        } catch (Error &error){
            return;
        };
    };
};
