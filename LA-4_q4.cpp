#include <iostream>
using namespace std;

#define MAX 100

class Circular_Queue {
    char arr[MAX];
    int front, rear;
public:
    Circular_Queue() { front = -1; rear = -1; }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return ((rear + 1) % MAX) == front;
    }

    void enqueue(char x) {
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
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Circular_Queue Underflow!\n";
            return '\0';
        }
        char value = arr[front];
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % MAX;
        }
        return value;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Circular_Queue is empty.\n";
            return '\0';
        }
        return arr[front];
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
    int char_count[256] = {0};
    cout << "Enter the length of the queue (max 100): ";
    int n;
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++){
        char value;
        cin >> value;
        char_count[(int)value]++;
        q.enqueue(value);
        while(!q.isEmpty()){
            if (char_count[(int)q.peek()] > 1)
                q.dequeue();
            else {
                cout << q.peek() << " ";
                break;
            }
        }
        if(q.isEmpty()){
            cout << "-1";
        }
    }
    return 0;
}