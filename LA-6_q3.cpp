#include <iostream>
using namespace std;

/* --- Doubly Linked List --- */
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};
DNode* dHead = nullptr;

void insertD(int data) {
    DNode* newNode = new DNode{data, nullptr, dHead};
    if (dHead) dHead->prev = newNode;
    dHead = newNode;
}

int sizeD() {
    int count = 0;
    DNode* temp = dHead;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* --- Circular Linked List --- */
struct CNode {
    int data;
    CNode* next;
};
CNode* cHead = nullptr;

void insertC(int data) {
    CNode* newNode = new CNode{data, nullptr};
    if (!cHead) {
        cHead = newNode;
        newNode->next = cHead;
        return;
    }
    CNode* temp = cHead;
    while (temp->next != cHead) temp = temp->next;
    temp->next = newNode;
    newNode->next = cHead;
}

int sizeC() {
    if (!cHead) return 0;
    int count = 0;
    CNode* temp = cHead;
    do {
        count++;
        temp = temp->next;
    } while (temp != cHead);
    return count;
}

int main() {
    insertD(10); insertD(20);
    insertC(1); insertC(2); insertC(3);
    cout << "Size of DLL: " << sizeD() << endl;
    cout << "Size of CLL: " << sizeC() << endl;
}
