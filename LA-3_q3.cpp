// LA-3_q3.cpp
// Program to check if an expression has balanced parentheses
#include <iostream>
using namespace std;

#define MAX 1000

class CharStack {
    int arr[MAX];
    int top;
public:
    CharStack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return '\0';
        }
        return arr[top];
    }
};

bool isBalanced(const char* expr) {
    CharStack s;
    for (int i = 0; expr[i] != '\0'; ++i) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;
            char top = s.peek();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    char expr[1000];
    cout << "Enter an expression: ";
    cin.getline(expr, 1000);
    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}
