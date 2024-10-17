#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Insert node at the front of the list
void insertAtFront(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert node at the end of the list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete a node from the list
void deleteNode(Node*& head, int data) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    Node* temp = head;

    // If the node to be deleted is the head node
    if (temp->data == data) {
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    // Traverse to find the node to be deleted
    while (temp != nullptr && temp->data != data) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node not found.\n";
        return;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

// Display the list from the beginning
void displayForward(Node* head) {
    Node* temp = head;
    cout << "List (Forward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display the list in reverse order
void displayBackward(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    // Traverse to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "List (Backward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Driver code to test the Doubly Linked List
int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtFront(head, 5);

    displayForward(head);
    displayBackward(head);

    deleteNode(head, 20);
    displayForward(head);

    deleteNode(head, 5);
    displayForward(head);

    return 0;
}
