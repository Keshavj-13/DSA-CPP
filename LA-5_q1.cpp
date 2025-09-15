#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (temp) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) {
            deleteAtBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    void search(int key) {
        int pos = 1;
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Not found\n";
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete at Beginning\n6. Delete at End\n7. Delete Specific\n";
        cout << "8. Search\n9. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
        case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
        case 3: cout << "Enter key and value: "; cin >> key >> val; list.insertBefore(key, val); break;
        case 4: cout << "Enter key and value: "; cin >> key >> val; list.insertAfter(key, val); break;
        case 5: list.deleteAtBeginning(); break;
        case 6: list.deleteAtEnd(); break;
        case 7: cout << "Enter key: "; cin >> key; list.deleteNode(key); break;
        case 8: cout << "Enter key: "; cin >> key; list.search(key); break;
        case 9: list.display(); break;
        }
    } while (choice != 0);

    return 0;
}
