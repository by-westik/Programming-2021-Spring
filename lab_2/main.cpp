#include <iostream>
#include <string>
#include <time.h>
//#include "Stack.h"
//#include "FunctionForWhere.h"
//#include "functional"
#include <utility>
#include "DynamicArray.h"

using namespace std;

int main () {
    int array[5] = {1, 2, 3, 4, 5};
    DynamicArray <int> n(array, 5);
    n.printArray();
    try{
        cout << n[0] << endl;
    }
    catch (Error &error){
        cout << "Error: " << error.getError() << endl;
    }
}
