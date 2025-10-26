#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};
DNode* dHead = nullptr;

void insertFrontD(int val) {
    DNode* newNode = new DNode{val, nullptr, dHead};
    if (dHead) dHead->prev = newNode;
    dHead = newNode;
}

void insertEndD(int val) {
    DNode* newNode = new DNode{val, nullptr, nullptr};
    if (!dHead) { dHead = newNode; return; }
    DNode* temp = dHead;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterD(int key, int val) {
    DNode* temp = dHead;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { cout << "Node not found!\n"; return; }
    DNode* newNode = new DNode{val, temp, temp->next};
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNodeD(int key) {
    DNode* temp = dHead;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { cout << "Node not found!\n"; return; }
    if (temp->prev) temp->prev->next = temp->next;
    else dHead = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

void searchNodeD(int key) {
    DNode* temp = dHead;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found!\n";
}

void displayD() {
    cout << "Doubly Linked List: ";
    for (DNode* temp = dHead; temp; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}

struct CNode {
    int data;
    CNode* next;
};
CNode* cHead = nullptr;

void insertEndC(int val) {
    CNode* newNode = new CNode{val, nullptr};
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

void insertFrontC(int val) {
    CNode* newNode = new CNode{val, nullptr};
    if (!cHead) {
        cHead = newNode;
        newNode->next = cHead;
        return;
    }
    CNode* temp = cHead;
    while (temp->next != cHead) temp = temp->next;
    temp->next = newNode;
    newNode->next = cHead;
    cHead = newNode;
}

void deleteNodeC(int key) {
    if (!cHead) return;
    CNode *curr = cHead, *prev = nullptr;
    while (curr->data != key) {
        if (curr->next == cHead) { cout << "Node not found!\n"; return; }
        prev = curr;
        curr = curr->next;
    }

    if (curr == cHead && curr->next == cHead) {
        delete curr;
        cHead = nullptr;
        return;
    }

    if (curr == cHead) {
        prev = cHead;
        while (prev->next != cHead) prev = prev->next;
        cHead = cHead->next;
        prev->next = cHead;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}

void searchNodeC(int key) {
    if (!cHead) { cout << "List empty!\n"; return; }
    CNode* temp = cHead;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != cHead);
    cout << "Not found!\n";
}

void displayC() {
    if (!cHead) { cout << "Empty list!\n"; return; }
    CNode* temp = cHead;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != cHead);
    cout << endl;
}

int main() {
    int choice, sub, val, key;
    do {
        cout << "\n====== MAIN MENU ======\n";
        cout << "1. Doubly Linked List Operations\n";
        cout << "2. Circular Linked List Operations\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nDoubly Linked List:\n1.Insert Front\n2.Insert End\n3.Insert After\n4.Delete\n5.Search\n6.Display\nEnter option: ";
            cin >> sub;
            if (sub == 1) { cout << "Enter data: "; cin >> val; insertFrontD(val); }
            else if (sub == 2) { cout << "Enter data: "; cin >> val; insertEndD(val); }
            else if (sub == 3) { cout << "After which node? "; cin >> key; cout << "Enter data: "; cin >> val; insertAfterD(key, val); }
            else if (sub == 4) { cout << "Enter node to delete: "; cin >> key; deleteNodeD(key); }
            else if (sub == 5) { cout << "Enter node to search: "; cin >> key; searchNodeD(key); }
            else if (sub == 6) displayD();
            break;

        case 2:
            cout << "\nCircular Linked List:\n1.Insert Front\n2.Insert End\n3.Delete\n4.Search\n5.Display\nEnter option: ";
            cin >> sub;
            if (sub == 1) { cout << "Enter data: "; cin >> val; insertFrontC(val); }
            else if (sub == 2) { cout << "Enter data: "; cin >> val; insertEndC(val); }
            else if (sub == 3) { cout << "Enter node to delete: "; cin >> key; deleteNodeC(key); }
            else if (sub == 4) { cout << "Enter node to search: "; cin >> key; searchNodeC(key); }
            else if (sub == 5) displayC();
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}
