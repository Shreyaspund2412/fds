#include <iostream>
#include <list>
#include <string>

// Class template for the queue item
template <typename T>
class QueueItem {
public:
    T data;          // Data of any type
    int priority;    // Priority as an integer

    // Constructor
    QueueItem(T d, int p) : data(d), priority(p) {}

    // Overload <= operator to compare items based on priority
    bool operator<=(const QueueItem& other) const {
        return this->priority >= other.priority;  // Higher priority comes first
    }
};

// Class for Priority Queue using inorder list
template <typename T>
class PriorityQueue {
private:
    std::list<QueueItem<T>> queueList; // Inorder list to store queue items

public:
    // Add an item with a specific priority to the queue
    void addItem(T data, int priority) {
        QueueItem<T> newItem(data, priority);

        // Insert in the list in such a way that the list remains ordered by priority
        typename std::list<QueueItem<T>>::iterator it;
        for (it = queueList.begin(); it != queueList.end(); ++it) {
            if (newItem <= *it) {
                break;
            }
        }
        queueList.insert(it, newItem);

        std::cout << "Added item: " << data << " with priority: " << priority << "\n";
    }

    // Retrieve and remove the item with the highest priority (at the front)
    void processItem() {
        if (!queueList.empty()) {
            QueueItem<T> item = queueList.front();
            std::cout << "Processing item: " << item.data << " with priority: " << item.priority << "\n";
            queueList.pop_front(); // Remove the processed item
        } else {
            std::cout << "Queue is empty!\n";
        }
    }

    // Display all items in the queue with their priorities
    void displayQueue() const {
        if (queueList.empty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "Current queue (in order of priority):\n";
        for (const auto& item : queueList) {
            std::cout << "Item: " << item.data << ", Priority: " << item.priority << "\n";
        }
    }
};

int main() {
    // PriorityQueue for strings
    PriorityQueue<std::string> pq;

    int choice;
    do {
        std::cout << "\nPriority Queue Menu:\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Process Item\n";
        std::cout << "3. Display Queue\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string data;
                int priority;
                std::cout << "Enter data (string): ";
                std::cin >> data;
                std::cout << "Enter priority (integer): ";
                std::cin >> priority;
                pq.addItem(data, priority);
                break;
            }
            case 2:
                pq.processItem();
                break;
            case 3:
                pq.displayQueue();
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
