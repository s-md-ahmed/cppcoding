#include <iostream>
using namespace std;

class LinkedList {
public:
    int data;
    LinkedList* next;
    LinkedList* head;
    LinkedList(int value) : data(value), next(nullptr), head(nullptr) {}

    // Function to add a node to the front of the linked list
    void insertFront(int value) {
        LinkedList* newNode = new LinkedList(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to delete a node from the front of the linked list
    void deleteFront() {
        if (head != nullptr) {
            LinkedList* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to print the data in the linked list
    void printList() {
        LinkedList* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList(42);
    int choice, value;

    do {
        cout << "\n1. Insert at Front\n";
        cout << "2. Delete from Front\n";
        cout << "3. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the front: ";
                cin >> value;
                myList.insertFront(value);
                break;

            case 2:
                myList.deleteFront();
                break;

            case 3:
                cout << "Current List: ";
                myList.printList();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
