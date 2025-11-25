#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int num){
        left=nullptr;
        right=nullptr;
        data=num;
    }
};

class tree{
    public:
    node* root;
    tree(){
        root = nullptr;
    }
    void insert(node* &root,int num){
        if(root==nullptr){
            root = new node(num);
            return;
        }
        if(root->data > num){
            insert(root->left,num);
        }else{
            insert(root->right,num);
        }
    }
    void pre(node* temp){
        if(temp!=NULL){
            cout << temp->data << " ";
            pre(temp->left);
            pre(temp->right);
        }
    }
    void in(node* temp){
        if(temp!=NULL){
            in(temp->left);
            cout << temp->data << " ";
            in(temp->right);
        }
    }
    void post(node* temp){
        if(temp!=NULL){
            post(temp->left);
            post(temp->right);
            cout << temp->data << " ";
        }
    }
};

int main(){
    tree mytree;
    mytree.insert(mytree.root,5);
    mytree.insert(mytree.root,8);
    mytree.insert(mytree.root,2);
    mytree.insert(mytree.root,854);
    mytree.insert(mytree.root,4);
    mytree.insert(mytree.root,0);
    mytree.insert(mytree.root,16);
    mytree.insert(mytree.root,3);
    mytree.insert(mytree.root,12);
    mytree.insert(mytree.root,9);
    mytree.insert(mytree.root,10);
    mytree.pre(mytree.root);
    cout << "\n";
    mytree.in(mytree.root);
    cout << "\n";
    mytree.post(mytree.root);
    return 0;
}