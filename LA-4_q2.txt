#include <iostream>
using namespace std;

#define MAX 100

class Circular_Queue {
    int arr[MAX];
    int front, rear;
public:
    Circular_Queue() { front = -1; rear = -1; }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return ((rear + 1) % MAX) == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular_Queue Overflow!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = x;
        cout << x << " enqueued to Circular_Queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Circular_Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued from Circular_Queue.\n";
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % MAX;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Circular_Queue is empty.\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Circular_Queue is empty.\n";
            return;
        }
        cout << "Circular_Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Circular_Queue q;
    int choice, value;
    do {
        cout << "\n--- Circular_Queue Menu ---\n";
        cout << "1. enqueue\n2. dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << (q.isEmpty() ? "Circular_Queue is empty.\n" : "Circular_Queue is not empty.\n");
                break;
            case 4:
                cout << (q.isFull() ? "Circular_Queue is full.\n" : "Circular_Queue is not full.\n");
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}