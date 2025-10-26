#include <iostream>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
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

void infixToPostfix(const char* infix, char* postfix) {
    CharStack s;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; ++i) {
        char ch = infix[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.peek();
                s.pop();
            }
            if (!s.isEmpty()) s.pop();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix[j++] = s.peek();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix[j++] = s.peek();
        s.pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[1000], postfix[1000];
    cout << "Enter an infix expression: ";
    cin.getline(infix, 1000);
    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
