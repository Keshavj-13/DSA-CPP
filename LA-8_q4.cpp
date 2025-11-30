#include <iostream>
#include <climits>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int v): data(v), left(nullptr), right(nullptr){}
};

bool isBSTUtil(node* root, long long minVal, long long maxVal){
    if(root == nullptr) return true;
    if(root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(node* root){
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}


int main(){
    node* bst = new node(20);
    bst->left = new node(10);
    bst->right = new node(30);
    bst->left->left = new node(5);
    bst->left->right = new node(15);
    bst->right->left = new node(25);
    bst->right->right = new node(35);

    cout << "Tree 1 (should be BST):\n";
    cout << "isBST (range method): " << (isBST(bst) ? "YES" : "NO") << '\n';

    node* notbst = new node(20);
    notbst->left = new node(10);
    notbst->right = new node(30);
    notbst->left->right = new node(25); 

    cout << "Tree 2 (should NOT be BST):\n";
    cout << "isBST (range method): " << (isBST(notbst) ? "YES" : "NO") << '\n';

    return 0;
}
