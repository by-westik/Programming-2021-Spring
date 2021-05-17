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

AVLtree *getMin(AVLtree *node){
    AVLtree *result = node;
    while(result -> left != NULL){
        result = result -> left;
    }
    return result;
};

AVLtree *del(AVLtree *node, int _value){
    if(!node){
        return NULL;
    };
    if(_value < node -> value){
        node -> left = del(node -> left, _value);
    } else if(_value > node -> value){
        node -> right = del(node -> right, _value);
    } else if (_value == node -> value){
        if((node -> left == NULL) || (node -> right == NULL)){
            AVLtree *temporary = NULL;
            if(node -> left != NULL){
                temporary = node -> left;
            } else {
                temporary = node -> right;
            };
            if(temporary == NULL){
                temporary = node;
                node = NULL;
            } else {
                *node = *temporary;
//                free(temporary);
            };
        } else {
            AVLtree *temporary_2 = getMin(node -> right);
            node -> value = temporary_2 -> value;
            node -> right = del(node -> right, temporary_2 -> value);
        };
            };

    if(node == NULL){
        return NULL;
    };

    node -> height = fixHeight(node);
    int balance = getBalance(node);

    if((balance > 1) && (getBalance(node -> left) >= 0)){//LL
        return rotateRight(node);
    } else if((balance < -1) && (getBalance(node -> right) <= 0)){//RR
        return rotateLeft(node);
    } else if((balance > 1) && (getBalance(node -> left) < 0)){
        node -> left = rotateLeft(node -> left);
        return rotateRight(node);
    } else if((balance < -1) && (getBalance(node -> right) > 0)){
        node -> right = rotateRight(node -> right);
        return rotateLeft(node);
    };
    return node;
};

void printLevel(AVLtree *node, int level){
    if(!node){
        return;
    } else if(level == 0){
        cout << node -> value << " ";
    } else {
        printLevel(node -> left, level - 1);
        printLevel(node -> right, level - 1);
    }
};
/*
void printTree(AVLtree *node){
    if(node == NULL)
        return;
    cout << node -> value << " ";
    printTree(node -> left);
    printTree(node -> right);
};*/
void printTree(AVLtree *node){
    int n = node -> height;
    for(int i = 0; i < n; i++){
        printLevel(node, i);
    };
    cout << endl;
};



int main(){
    AVLtree *node = NULL;
    node = insert(node, 5);
    printTree(node);
    node = insert(node, 10);
    printTree(node);
    node = insert(node, 15);
    printTree(node);
    node = insert(node, 20);
    printTree(node);
    node = insert(node, 25);
    printTree(node);
    node = insert(node, 3);
    printTree(node);
    node = insert(node, 12);
    printTree(node);
    //    cout << getMin(node) -> value << endl;
    node = del(node, 20);
    printTree(node);
    return 0;
};
