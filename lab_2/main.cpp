#include <iostream>
#include "Sequence.h"
#include "Stack.h"
#include <bits/stdc++.h>
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
    st.pop();
    st.printStack();

    return 0;
}
