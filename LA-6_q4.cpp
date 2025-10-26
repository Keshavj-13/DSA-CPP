#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};
Node* head = nullptr;

void insertEnd(char c) {
    Node* newNode = new Node{c, nullptr, nullptr};
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome() {
    if (!head) return true;
    Node* left = head, *right = head;
    while (right->next) right = right->next;

    while (left && right && left != right && right->next != left) {
        if (tolower(left->data) != tolower(right->data)) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s = "madam";
    for (char c : s) insertEnd(c);
    cout << (isPalindrome() ? "True" : "False") << endl;
}
