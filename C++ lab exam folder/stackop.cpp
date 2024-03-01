#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class STACK {
private:
    int arr[MAX_SIZE];
    int top;

public:
    STACK() : top(-1) {}

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push element " << element << endl;
            return;
        }
        arr[++top] = element;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return -1;
        }
        return arr[top--];
    }

    friend STACK operator+(STACK &s, int element);
    friend STACK operator-(STACK &s);

    friend ostream& operator<<(ostream& os, const STACK& s);
};

STACK operator+(STACK &s, int element) {
    s.push(element);
    return s;
}

STACK operator-(STACK &s) {
    int poppedElement = s.pop();
    if (poppedElement != -1)
        cout << "Popped Element: " << poppedElement << endl;
    return s;
}

ostream& operator<<(ostream& os, const STACK& s) {
    os << "Stack Contents: ";
    for (int i = s.top; i >= 0; --i) {
        os << s.arr[i] << " ";
    }
    os << endl;
    return os;
}

int main() {
    STACK s;
    int choice, element;

    do {
        cout << "\nStack Operations:" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Display stack" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> element;
                s = s + element;
                break;

            case 2:
                s = -s; // Pop one element
                break;

            case 3:
                cout << s;
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
