#include <iostream>

template<typename T, int capacity>
class Queue {
private:
    T arr[capacity];
    int front;
    int rear;

public:
    // Constructor
    Queue() : front(0), rear(-1) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return rear < front;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Function to add an element to the queue
    void enqueue(T item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        arr[++rear] = item;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        ++front;
    }

    // Function to get the front element of the queue
    T getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            exit(1);
        }
        return arr[front];
    }

    // Function to get the rear element of the queue
    T getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            exit(1);
        }
        return arr[rear];
    }

    // Function to display the contents of the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue<int, 5> intQueue; // Queue of integers with capacity 5
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.display(); // Output: 1 2 3

    intQueue.dequeue();
    intQueue.display(); // Output: 2 3

    std::cout << "Front element: " << intQueue.getFront() << std::endl; // Output: 2
    std::cout << "Rear element: " << intQueue.getRear() << std::endl;   // Output: 3

    Queue<double, 3> doubleQueue; // Queue of doubles with capacity 3
    doubleQueue.enqueue(2.5);
    doubleQueue.enqueue(3.7);
    doubleQueue.display(); // Output: 2.5 3.7

    return 0;
}
