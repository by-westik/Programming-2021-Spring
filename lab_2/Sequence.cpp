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
    cout << "Insert element in a(index 7)" << endl;
    a.insertAt(456, 7);
    a.printArraySequence();
    ArraySequence<int> *sub_array = new ArraySequence<int>(*dynamic_cast <ArraySequence<int>*>(a.getSubsequence(3, 7)));
    cout << "Sub array" << endl;
    sub_array -> printArraySequence();
    cout << "LinkedList" << endl;
    LinkedListSequence<int> l(array_1, 5);
    cout << "Create LinkedListSequence l" << endl;
    l.printLinkedListSequence();
    cout << "First l element - " << l.getFirst()  << " last l element - " << l.getLast() << " len of l - " << l.getLength() << endl;
    cout << "Create copy LinkedListSequence l_copy" << endl;
    LinkedListSequence<int> l_copy(l);
    l_copy.printLinkedListSequence();
    cout << "First l_copy element - " << l_copy.getFirst()  << " last l_copy element - " << l_copy.getLast() << " len of l_copy - " << l_copy.getLength() << endl;
    cout << "Append 7 elements in l" << endl;
    for(int i = 0; i < 7; i++){
        l.append(i);
    }
    l.printLinkedListSequence();
    cout << "First l element - " << l.getFirst()  << " last l element - " << l.getLast() << " len of l - " << l.getLength() << endl;
    cout << "Prepend 5 elements in l" << endl;
    for(int i = 0; i < 5; i++){
        l.prepend(i);
    }
    l.printLinkedListSequence();
    cout << "First l element - " << l.getFirst()  << " last l element - " << l.getLast() << " len of l - " << l.getLength() << endl;
    cout << "Create sublist from l (startIndex = 4; endIndex = 9" << endl;
    cout << "Insert element 456 in l (index = 0)" << endl;
    l.insertAt(456, 9);
    l.printLinkedListSequence();
    cout << "First l element - " << l.getFirst()  << " last l element - " << l.getLast() << " len of l - " << l.getLength() << endl;
    LinkedListSequence<int> *sub_l = new LinkedListSequence<int>(*dynamic_cast <LinkedListSequence<int>*>(l.getSubsequence(3, 11)));
    sub_l -> printLinkedListSequence();
    cout << "First  sub_l element - " <<  sub_l -> getFirst()  << " last  sub_l element - " <<  sub_l -> getLast() << " len of  sub_l - " <<  sub_l -> getLength() << endl;
    return 0;

}
