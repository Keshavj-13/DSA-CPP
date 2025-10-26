#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;

void insertEnd(int data) {
    Node* newNode = new Node{data, nullptr};
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void display() {
    if (!head) return;
    Node* temp = head;
    cout << "Circular List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    insertEnd(67);
    insertEnd(21);
    insertEnd(9);
    insertEnd(10);
    insertEnd(8);
    display();
}
