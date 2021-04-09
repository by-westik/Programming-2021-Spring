#include <iostream>
#include "Sequence.h"
#include "Stack.h"
using namespace std;

int main () {
    Stack<int> st;
    st.push(10);
    st.printStack();
    st.push(30);
    st.printStack();
    st.push(20);
    st.printStack();
    st.push(5);
    st.printStack();
    st.push(1);
    st.printStack();
    st.map();
    cout << endl;
    st.printStack();
    Stack<int> sub_st(*st.subStack(2,4));
    sub_st.printStack();
    Stack<int> con_st(*st.concatStack(sub_st));
    con_st.printStack();
    return 0;
}
