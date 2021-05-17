#include <iostream>
#include "DynamicArray.h"
#include "binaryHeap.h"

using namespace std;

int main(){
    int array[9] = {7, 2, 1, 3, 25, 17, 36, 19, 100};
    binaryHeap <int, DynamicArray> *h = new binaryHeap <int, DynamicArray> (array, 9);
    h -> printHeap();
    cout << h -> getMin() << endl;
    cout << h -> getMax() << endl;
    h -> insertKey(12);
    h -> printHeap();
    h -> deleteMax();
    h -> printHeap();
    h -> updateKey(0, 100);
    h -> printHeap();
    h -> updateKey(3, 128);
    h -> printHeap();
    cout << h -> getMax() << endl;
    return 0;
};
