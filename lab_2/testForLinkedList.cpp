#include <cassert>
#include "LinkedList.h"

void testForEmptyConstructor();
void testForCopyConstructors();
void testForGet();
void testForAppend();
void testForPrepend();
void testForInsert();
void testForSubList();
void testForConcat();

int main(){
    testForEmptyConstructor();
    testForCopyConstructors();
    testForGet();
    testForAppend();
    testForPrepend();
    testForInsert();
    testForSubList();
    testForConcat();
}

void testForEmptyConstructor(){
    LinkedList <int> i;
    assert(i.getLength() == 0);
    LinkedList <char> c;
    assert(c.getLength() == 0);
    LinkedList <double> d;
    assert(d.getLength() == 0);
}
void testForCopyConstructors(){
    int array[5] = {1, 6, 3, 24, 5};
    LinkedList <int> l(array, 5);
    LinkedList <int> l_copy(l);
    assert(l.getLength() == 5);
    assert(l_copy.getLength() == 5);
    assert(l_copy.getLength() == l.getLength());
    for(int i = 0; i < 5; i++){
        assert(l[i] == array[i]);
        assert(l[i] == l_copy[i]);
        assert(l[i] == array[i]);
    }
}

void testForGet(){
    int array[5] = {1, 6, 3, 24, 5};
    LinkedList <int> l(array, 5);
    assert(l.getFirst() == array[0]);
    assert(l.getLast() == array[4]);
    for(int i = 0; i < 5; i++){
        assert(l.get(i) == array[i]);
    }
}


void testForAppend(){
    int array[5] = {1, 6, 3, 24, 5};
    LinkedList <int> l(array, 5);
    for(int i = 0; i < 5; i++){
        l.append(i);
        assert(l.getFirst() == i);
    }
}

void testForPrepend(){
    int array[5] = {1, 6, 3, 24, 5};
    LinkedList <int> l(array, 5);
    for(int i = 0; i < 5; i++){
        l.prepend(i);
        assert(l.getLast() == i);
    }
}

void testForInsert(){
    int array[5] = {7, 8, 9, 10, 11};
    LinkedList <int> l(array, 5);
    for(int i = 0; i < 5; i++){
        l.insertAt(i, i);
        assert(l.get(i) == i);
    }
}

void testForSubList(){
    int array[10] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    LinkedList <int> l(array, 10);
    LinkedList <int> l_1;
    l.getSubList(0, 1, l_1);
    for(int i = 0; i < l_1.getLength(); i++){
        assert(l[i] == l_1[i]);
    }
    LinkedList <int> l_2;
    l.getSubList(4, 9, l_2);
    int j = 4;
    for(int i = 0; i < l_2.getLength(); i++){
        assert(l_2[i] == l[j]);
        j++;
    }
}

void testForConcat(){
    int array[10] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    int array_2[5] = {56, 67, 78, 89, 90};
    LinkedList <int> l(array, 10);
    LinkedList <int> l_2(array_2, 5);
    LinkedList <int> l_c;
    l.concat(&l_2, l_c);
    int i = 0;
    for(i; i < l.getLength(); i++){
        assert(l[i] == l_c[i]);
        assert(l.get(i) == l_c.get(i));
        assert(l_c.get(i) == array[i]);
    }
    for(int j = 0; j < l_2.getLength(); j++){
        assert(l_2[j] == l_c[i]);
        assert(l_2.get(j) == l_c.get(i));
        assert(l_c.get(i) == array_2[j]);
        i++;
    }
}