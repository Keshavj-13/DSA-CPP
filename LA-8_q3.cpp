#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int num){
        left = nullptr;
        right = nullptr;
        data = num;
    }
};

class tree{
public:
    node* root;
    tree(){ root = nullptr; }

    // Insert (no duplicates)
    void insert(node*& r, int key){
        if(r == nullptr){
            r = new node(key);
            return;
        }
        if(key == r->data) return; // no duplicates
        if(key < r->data) insert(r->left, key);
        else insert(r->right, key);
    }
    void insert(int key){ insert(root, key); }

    // Find minimum in subtree
    node* findMin(node* r){
        if(!r) return nullptr;
        while(r->left) r = r->left;
        return r;
    }

    // Delete a key and return new subtree root
    node* deleteNode(node* r, int key){
        if(r == nullptr) return nullptr;
        if(key < r->data) r->left = deleteNode(r->left, key);
        else if(key > r->data) r->right = deleteNode(r->right, key);
        else {
            // node found
            if(r->left == nullptr){
                node* tmp = r->right;
                delete r;
                return tmp;
            } else if(r->right == nullptr){
                node* tmp = r->left;
                delete r;
                return tmp;
            } else {
                // two children: replace with inorder successor (min in right)
                node* succ = findMin(r->right);
                r->data = succ->data;
                r->right = deleteNode(r->right, succ->data);
            }
        }
        return r;
    }
    void remove(int key){ root = deleteNode(root, key); }

    // Maximum depth (height)
    int maxDepth(node* r){
        if(r == nullptr) return 0;
        int l = maxDepth(r->left);
        int ri = maxDepth(r->right);
        return 1 + (l > ri ? l : ri);
    }
    int maxDepth(){ return maxDepth(root); }

    // Minimum depth: shortest distance from root to a leaf
    int minDepth(node* r){
        if(r == nullptr) return 0;
        if(r->left == nullptr && r->right == nullptr) return 1;
        if(r->left == nullptr) return 1 + minDepth(r->right);
        if(r->right == nullptr) return 1 + minDepth(r->left);
        int l = minDepth(r->left);
        int ri = minDepth(r->right);
        return 1 + (l < ri ? l : ri);
    }
    int minDepth(){ return minDepth(root); }

    // Inorder traversal (sorted order)
    void inorder(node* r){
        if(!r) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    void inorder(){ inorder(root); }
};

int main(){
    tree t;
    // Insert sample values (no duplicates will be inserted)
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    for(int v: vals) t.insert(v);

    cout << "Initial inorder (sorted): "; t.inorder(); cout << '\n';
    cout << "Max depth: " << t.maxDepth() << "\n";
    cout << "Min depth: " << t.minDepth() << "\n\n";

    // Delete a leaf
    cout << "Delete 10 (leaf)\n";
    t.remove(10);
    cout << "Inorder: "; t.inorder(); cout << '\n';
    cout << "Max depth: " << t.maxDepth() << ", Min depth: " << t.minDepth() << "\n\n";

    // Delete node with one child
    cout << "Delete 30 (has children)\n";
    t.remove(30);
    cout << "Inorder: "; t.inorder(); cout << '\n';
    cout << "Max depth: " << t.maxDepth() << ", Min depth: " << t.minDepth() << "\n\n";

    // Delete node with two children
    cout << "Delete 50 (root, two children)\n";
    t.remove(50);
    cout << "Inorder: "; t.inorder(); cout << '\n';
    cout << "Max depth: " << t.maxDepth() << ", Min depth: " << t.minDepth() << "\n";

    return 0;
}
