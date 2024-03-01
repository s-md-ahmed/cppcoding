#include <iostream>
using namespace std;
class DoublyLinkedList {
public:
    DoublyLinkedList* head;
    int data;
    DoublyLinkedList* prev;
    DoublyLinkedList* next;
public:
    DoublyLinkedList() : head(nullptr) {}

    // Function to create a new node and set its data
    DoublyLinkedList* createNode(int value) {
        DoublyLinkedList* newNode = new DoublyLinkedList;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

    // Function to insert a node at the specified position in the list
    void insertNode(int value, int position) {
        DoublyLinkedList* newNode = createNode(value);
        if (head == nullptr || position == 1) {
            if (head != nullptr)
                head->prev = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
        DoublyLinkedList* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Invalid position\n";
            delete newNode;
            return;
        }
        newNode->next = current->next;
        if (current->next != nullptr)
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }

    // Function to delete a node from the specified position in the list
    void deleteNode(int position) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }
        DoublyLinkedList* current = head;
        if (position == 1) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete current;
            return;
        }
        for (int i = 1; i < position && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Invalid position\n";
            return;
        }
        if (current->next != nullptr)
            current->next->prev = current->prev;
        current->prev->next = current->next;
        delete current;
    }

    // Function to display the elements of the list
    void display() {
        DoublyLinkedList* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList myList;
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Delete node\n";
        cout << "3. Display list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> position;
                myList.insertNode(value, position);
                cout << "List after insertion: ";
                myList.display();
                break;
            case 2:
                cout << "Enter position to delete: ";
                cin >> position;
                myList.deleteNode(position);
                cout << "List after deletion: ";
                myList.display();
                break;
            case 3:
                cout << "List: ";
                myList.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
