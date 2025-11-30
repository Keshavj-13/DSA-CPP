#include <iostream>
#include <climits>
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
    // Traversals
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

    // Recursive search
    node* searchRecursive(node* r, int key){
        if(r==nullptr || r->data==key) return r;
        if(key < r->data) return searchRecursive(r->left, key);
        return searchRecursive(r->right, key);
    }
    node* searchRecursive(int key){ return searchRecursive(root, key); }

    // Iterative (non-recursive) search
    node* searchIterative(int key){
        node* cur = root;
        while(cur != nullptr){
            if(cur->data == key) return cur;
            if(key < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return nullptr;
    }

    // Find minimum in a subtree (iterative)
    node* findMin(node* r){
        if(r==nullptr) return nullptr;
        while(r->left) r = r->left;
        return r;
    }
    node* findMin(){ return findMin(root); }

    // Find maximum in a subtree (iterative)
    node* findMax(node* r){
        if(r==nullptr) return nullptr;
        while(r->right) r = r->right;
        return r;
    }
    node* findMax(){ return findMax(root); }

    // In-order successor of a node with given key
    node* inorderSuccessor(int key){
        node* target = searchIterative(key);
        if(!target) return nullptr;
        if(target->right) return findMin(target->right);
        node* succ = nullptr;
        node* ancestor = root;
        while(ancestor != nullptr && ancestor != target){
            if(target->data < ancestor->data){
                succ = ancestor;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return succ;
    }

    // In-order predecessor of a node with given key
    node* inorderPredecessor(int key){
        node* target = searchIterative(key);
        if(!target) return nullptr;
        if(target->left) return findMax(target->left);
        node* pred = nullptr;
        node* ancestor = root;
        while(ancestor != nullptr && ancestor != target){
            if(target->data > ancestor->data){
                pred = ancestor;
                ancestor = ancestor->right;
            }else{
                ancestor = ancestor->left;
            }
        }
        return pred;
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

    // Demonstrate searches
    int keysToSearch[] = {63, 100, 6};
    for(int k: keysToSearch){
        node* r = mytree.searchRecursive(k);
        cout << "searchRecursive(" << k << ") -> ";
        if(r) cout << r->data << "\n"; else cout << "not found\n";
        r = mytree.searchIterative(k);
        cout << "searchIterative(" << k << ") -> ";
        if(r) cout << r->data << "\n"; else cout << "not found\n";
        cout << "\n";
    }

    // Min and Max
    node* minN = mytree.findMin();
    node* maxN = mytree.findMax();
    cout << "Min: " << (minN? minN->data : INT_MIN) << "\n";
    cout << "Max: " << (maxN? maxN->data : INT_MAX) << "\n" << endl;

    // Successor and predecessor examples
    int checkVals[] = {25, 37, 50, 93};
    for(int k: checkVals){
        node* s = mytree.inorderSuccessor(k);
        node* p = mytree.inorderPredecessor(k);
        cout << "Value " << k << ": successor -> ";
        if(s) cout << s->data; else cout << "none";
        cout << ", predecessor -> ";
        if(p) cout << p->data; else cout << "none";
        cout << "\n";
    }

    return 0;
}