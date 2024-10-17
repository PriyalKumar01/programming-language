#include <iostream>
using namespace std;

#define MAX 1000  // Maximum size of the stack

class Stack {
    int top;            // Index to the top of the stack
    int arr[MAX];       // Stack array

public:
    Stack() {           // Constructor to initialize top
        top = -1;
    }

    bool push(int x);   // Function to add an element to the stack
    int pop();          // Function to remove the top element
    int peek();         // Function to get the top element
    bool isEmpty();     // Check if the stack is empty
    bool isFull();      // Check if the stack is full
};

// Function to add an element to the stack (push)
bool Stack::push(int x) {
    if (isFull()) {
        cout << "Stack Overflow. Cannot push " << x << " into the stack.\n";
        return false;
    }
    arr[++top] = x;
    cout << x << " pushed into stack.\n";
    return true;
}

// Function to remove the top element (pop)
int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow. No element to pop.\n";
        return -1;
    }
    return arr[top--];
}

// Function to get the top element (peek)
int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return -1;
    }
    return arr[top];
}

// Check if the stack is empty
bool Stack::isEmpty() {
    return (top < 0);
}

// Check if the stack is full
bool Stack::isFull() {
    return (top >= MAX - 1);
}

// Driver code to test the stack
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    cout << s.pop() << " popped from stack.\n";

    cout << "Top element after pop is: " << s.peek() << endl;

    return 0;
}
