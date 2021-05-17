#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int _data)
    :data(_data)
    ,left(NULL)
    ,right(NULL)
    {
    };
};

bool isBinarySearchTree(Node* root, Node* l=NULL, Node* r=NULL){
    if (root == NULL)
        return true;
    if ((l != NULL) && ( root->data <= l->data))
        return false;
    if ((r != NULL) && (root->data >= r->data))
        return false;
    return (isBinarySearchTree(root->left, l, root)) && (isBinarySearchTree(root->right, root, r));
}

int main(){
    Node *root = new Node(5);
    root -> left = new Node(2);
    root -> right = new Node(7);
//root -> left -> left = new Node(0);// - BST
//root -> left -> left = new Node(11)// - not BST
    root -> right -> right = new Node(12);
    if (isBinarySearchTree(root,NULL,NULL)){
        cout << "Is BST" << endl;;
    } else {
        cout << "Not a BST" << endl;
    }
    return 0;
}