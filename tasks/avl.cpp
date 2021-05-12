#include<iostream>
#include <algorithm>

using namespace std;

class AVLtree{
public:
    int value;
    AVLtree *left;
    AVLtree *right;
    int height;
    AVLtree(){};
    AVLtree(int _value)
    :value(_value)
    ,left(NULL)
    ,right(NULL)
    ,height(1)
    {
    };
};

int getHeight(AVLtree *node){
    return node ? node -> height: 0;
};

int fixHeight(AVLtree *node){
    return max(getHeight(node -> left), getHeight(node -> right)) + 1;
}

AVLtree *rotateRight(AVLtree *node){
    AVLtree *result = node -> left;
    AVLtree *left = result -> right;
    result -> right = node;
    node -> left = left;
    node -> height = fixHeight(node);
    result -> height = fixHeight(result);
    return result;
};

AVLtree *rotateLeft(AVLtree *node){
    AVLtree *result = node -> right;
    AVLtree *right = result -> left;
    result -> left = node;
    node -> right = right;
    node -> height = fixHeight(node);
    result ->height = fixHeight(result);
    return result;
};

int getBalance(AVLtree *node){
    if (node == NULL){
        return 0;
    };
    return getHeight(node -> left) - getHeight(node -> right);
};

AVLtree* insert(AVLtree* node, int _value){
    if (node == NULL){
        return(new AVLtree(_value));
    };
    if (_value < node -> value){
        node -> left = insert(node -> left, _value);
    } else if (_value > node -> value){
        node -> right = insert(node -> right, _value);
    } else {
        return node;
    };

    node -> height = fixHeight(node);
    int balance = getBalance(node);
    if ((balance > 1) && (_value < node -> left -> value)){
        return rotateRight(node);
    } else if ((balance < -1) && (_value > node -> right -> value)){
        return rotateLeft(node);
    } else if ((balance > 1) && (_value > node -> left -> value)){
        node -> left = rotateLeft(node -> left);
        return rotateRight(node);
    } else if ((balance < -1) && (_value < node -> right -> value)){
        node -> right = rotateRight(node -> right);
        return rotateLeft(node);
    };
    return node;
};

void printTree(AVLtree *node){
    if(node == NULL)
        return;
    cout << node -> value << " ";
    printTree(node -> left);
    printTree(node -> right);
};

int main(){
    AVLtree *node = NULL;
    node = insert(node, 5);
    printTree(node);
    cout << endl;
    node = insert(node, 10);
    printTree(node);
    cout << endl;
    node = insert(node, 15);
    printTree(node);
    cout << endl;
    node = insert(node, 20);
    printTree(node);
    cout << endl;
    node = insert(node, 25);
    printTree(node);
    cout << endl;
    node = insert(node, 12);
    printTree(node);
    cout << endl;
    node = insert(node, 3);
    printTree(node);
    cout << endl;
    return 0;
};