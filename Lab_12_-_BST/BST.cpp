#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node * left;
    node * right;
};

node* insert_to_bst(node* root, int val){
    if(root == NULL){
        node* newNode = new node();
        newNode->left = newNode->right = NULL;
        newNode->data = val;
        root = newNode;
    }
    else if(val < root->data)
        root->left = insert_to_bst(root->left, val);
    else if(val > root->data)
        root->right = insert_to_bst(root->right, val);

    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout <<root->data << " ";
        inorder(root->right);
    }
}

void find_in_bst(node* root, int key){
    if(root == NULL)
        cout << "Not found!!" << endl;
    else if(root->data == key)
        cout << "Found!!" << endl;
    else if(key < root->data)
        find_in_bst(root->left, key);
    else if(key > root->data)
        find_in_bst(root->right, key);
}
