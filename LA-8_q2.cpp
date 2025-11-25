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
    void search(node* temp,int num){
        if(temp->data == num){
            cout<< " found element";
            return;
        }
        if(temp->data > num){
            cout<< " left";
            search(temp->left,num);
        }else{
            cout<< " right";
            search(temp->right,num);
        }
    }
};

int main(){
    tree mytree;
    mytree.insert(mytree.root,50);
    mytree.insert(mytree.root,25);
    mytree.insert(mytree.root,75);
    mytree.insert(mytree.root,12);
    mytree.insert(mytree.root,37);
    mytree.insert(mytree.root,63);
    mytree.insert(mytree.root,87);
    mytree.insert(mytree.root,6);
    mytree.insert(mytree.root,18);
    mytree.insert(mytree.root,30);
    mytree.insert(mytree.root,43);
    mytree.insert(mytree.root,55);
    mytree.insert(mytree.root,68);
    mytree.insert(mytree.root,81);
    mytree.insert(mytree.root,93);
    mytree.insert(mytree.root,2);
    mytree.insert(mytree.root,85);
    mytree.insert(mytree.root,4);
    mytree.insert(mytree.root,0);
    mytree.insert(mytree.root,16);
    mytree.insert(mytree.root,3);
    mytree.insert(mytree.root,12);
    mytree.insert(mytree.root,9);
    mytree.insert(mytree.root,10);
    mytree.search(mytree.root,63);
    return 0;
}