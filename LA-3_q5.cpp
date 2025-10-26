#include <iostream>
using namespace std;

#define MAX 1000

class IntStack {
    int arr[MAX];
    int top;
public:
    IntStack() { top = -1; }

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

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return 0;
        }
        return arr[top];
    }
};


int evaluatePostfix(const char* expr) {
    IntStack s;
    for (int i = 0; expr[i] != '\0'; ++i) {
        char ch = expr[i];
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int val2 = s.peek(); s.pop();
            int val1 = s.peek(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; ++j) res *= val1;
                    s.push(res);
                    break;
                }
            }
        }
    }
    return s.peek();
}

int main() {
    char expr[1000];
    cout << "Enter a postfix expression (single-digit operands): ";
    cin.getline(expr, 1000);
    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
