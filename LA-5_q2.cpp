#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void countAndDelete(Node*& head, int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        if (temp->data == key) {
            count++;
            if (prev) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                head = temp->next;
                delete temp;
                temp = head;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    cout << "Count: " << count << endl;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    display(head);
    countAndDelete(head, 1);
    display(head);

    return 0;
}
