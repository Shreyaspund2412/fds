#include <iostream>
#define MAX 5 // Define maximum number of orders (M)

class PizzaParlor {
private:
    int orders[MAX];  // Array to store the orders
    int front, rear;  // Pointers to track the front and rear of the queue

public:
    // Constructor to initialize the circular queue
    PizzaParlor() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an order to the queue
    void placeOrder(int orderID) {
        if (isFull()) {
            std::cout << "The parlor is at full capacity. Cannot accept more orders.\n";
            return;
        }

        if (front == -1) {  // If queue is empty
            front = 0;
            rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;  // Circular wrap-around
        } else {
            rear++;  // Normal case
        }

        orders[rear] = orderID;
        std::cout << "Order " << orderID << " has been placed successfully.\n";
    }

    // Function to serve an order (remove from the queue)
    void serveOrder() {
        if (isEmpty()) {
            std::cout << "No orders to serve.\n";
            return;
        }

        std::cout << "Serving order " << orders[front] << ".\n";

        if (front == rear) {
            // Only one order was in the queue
            front = -1;
            rear = -1;
        } else if (front == MAX - 1) {
            // Circular wrap-around
            front = 0;
        } else {
            front++;
        }
    }

    // Function to display the current orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            std::cout << "No orders in the queue.\n";
            return;
        }

        std::cout << "Current orders in the queue: ";
        if (rear >= front) {
            // If rear is ahead of or at front
            for (int i = front; i <= rear; i++) {
                std::cout << orders[i] << " ";
            }
        } else {
            // Circular queue case
            for (int i = front; i < MAX; i++) {
                std::cout << orders[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                std::cout << orders[i] << " ";
            }
        }
        std::cout << "\n";
    }
};

int main() {
    PizzaParlor parlor;
    int choice, orderID;

    do {
        std::cout << "\nPizza Parlor Order Management System\n";
        std::cout << "1. Place Order\n";
        std::cout << "2. Serve Order\n";
        std::cout << "3. Display Orders\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter order ID: ";
                std::cin >> orderID;
                parlor.placeOrder(orderID);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}



