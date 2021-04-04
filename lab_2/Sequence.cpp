#include <iostream>
#include "Sequence.h"

using namespace std;

int main() {
    int array_1[5] = {1, 2, 3, 4, 5};
    ArraySequence<int> a(array_1, 5);
    ArraySequence<int>a_copy(a);
    cout << "ArraySequence a" << endl;
    a.printArraySequence();
    cout << "ArraySequence a_copy" << endl;
    a_copy.printArraySequence();
    cout << "First a element - " << a.getFirst()  << " last a element - " << a.getLast() << " element of index 3 - " << a.get(3) << endl;
    cout << "Append 7 elements in a" << endl;
    for(int i = 0 ; i < 7; i++){
        a.append(i);
    }
    a.printArraySequence();
    cout << "First a element - " << a.getFirst()  << " last a element - " << a.getLast() << " len of a - " << a.getLength() << endl;
    cout << "Prepend 4 elements in a" << endl;
    for(int i = 0; i < 4; i++){
        a.prepend(i);
    }
    a.printArraySequence();
    cout << "Create subSequence from a (startIndex = 3, end Index = 8)" << endl;
    ArraySequence <int>* a_sub;
    a_sub = dynamic_cast <ArraySequence<int>*> (a.getSubsequence(3,8));
    cout << a_sub -> getLength() << endl;
    a_sub -> printArraySequence();
    return 0;
}
