#include <cassert>
#include "DynamicArray.h"

void testForSizeConstructor();
void testForCopyConstructors();
void testForSetGet();
void testForResize();

int main(){
    testForSizeConstructor();
    testForCopyConstructors();
    testForSetGet();
    testForResize();
}

void testForSizeConstructor(){
    DynamicArray <int> i(3);
    assert(i.getSize() == 3);
    DynamicArray <double> d(5);
    assert(d.getSize() == 5);
    DynamicArray <char> c(7);
    assert(c.getSize() == 7);
}

void testForCopyConstructors(){
    int array[5] = {1, 3, 4, 5, 6};
    DynamicArray <int> a(array, 5);
    DynamicArray <int> a_copy(a);
    assert(a.getSize() ==  5);
    assert(a_copy.getSize() == 5);
    assert(a.getSize() == a_copy.getSize());
    for(int i = 0; i < 5; i++){
        assert(array[i] ==  a[i]);
        assert(a[i] ==  a_copy[i]);
        assert(array[i] == a_copy[i]);
    }
}

void testForSetGet(){
    DynamicArray <int> a(3);
    for(int i = 0; i < 3; i++){
        a.set(i, i);
        assert(a.get(i) == i);
    }
    for(int i = 0; i < 3; i++){
       assert(a.get(i) == i);
    }
}

void testForResize(){
    DynamicArray <int> a(0);
    a.resize(13);
    assert(a.getSize() == 13);
    a.resize(2);
    assert(a.getSize() == 2);
}