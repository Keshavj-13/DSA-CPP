#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(char x) {
        if (!isFull()) arr[++top] = x;
    }
    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }
};

int main() {
    Stack s;
    char value[MAX];
    cout << "Enter your String: ";
    cin.getline(value, MAX);
    int len = 0;
    while (value[len] != '\0') {
        s.push(value[len]);
        len++;
    }
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
    return 0;
}