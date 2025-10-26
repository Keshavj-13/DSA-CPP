#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* head = new Node{2, nullptr};
    head->next = new Node{4, nullptr};
    head->next->next = new Node{6, nullptr};
    head->next->next->next = head;
    cout << (isCircular(head) ? "True" : "False") << endl;
}
