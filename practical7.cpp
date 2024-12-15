#include <iostream>
#include <string>

using namespace std;

// Node structure for the linked list
struct Member {
    string prn;
    string name;
    Member* next;
};

// Class for the Pinnacle Club
class PinnacleClub {
private:
    Member* head;
    Member* tail;

public:
    PinnacleClub() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to add a member
    void addMember(const string& prn, const string& name) {
        Member* newMember = new Member{prn, name, nullptr};

        // If the list is empty, set head and tail
        if (!head) {
            head = newMember; // First member (President)
            tail = newMember; // Also the tail
        } else {
            tail->next = newMember; // Add to the end
            tail = newMember; // Update tail
        }
    }

    // Function to delete a member by PRN
    void deleteMember(const string& prn) {
        if (!head) {
            cout << "No members to delete." << endl;
            return;
        }

        Member* current = head;
        Member* previous = nullptr;

        // Search for the member to delete
        while (current != nullptr && current->prn != prn) {
            previous = current;
            current = current->next;
        }

        // If the member was not found
        if (!current) {
            cout << "Member with PRN " << prn << " not found." << endl;
            return;
        }

        // If the member to delete is the head
        if (current == head) {
            head = head->next;
        } else {
            previous->next = current->next;
        }

        // If the member to delete is the tail
        if (current == tail) {
            tail = previous;
        }

        delete current; // Free memory
        cout << "Member with PRN " << prn << " deleted." << endl;
    }

    // Function to compute total number of members
    int totalMembers() {
        int count = 0;
        Member* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to display members
    void displayMembers() {
        if (!head) {
            cout << "No members in the club." << endl;
            return;
        }

        Member* current = head;
        while (current != nullptr) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Function to concatenate two lists
    void concatenate(PinnacleClub& otherClub) {
        if (!head) {
            head = otherClub.head;
            tail = otherClub.tail;
        } else if (otherClub.head) {
            tail->next = otherClub.head;
            tail = otherClub.tail;
        }
        otherClub.head = nullptr; // Clear the other list
        otherClub.tail = nullptr;
    }

    // Destructor to free memory
    ~PinnacleClub() {
        while (head) {
            Member* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Function to take user input for member details
void addMemberInput(PinnacleClub& club) {
    string prn, name;
    cout << "Enter PRN: ";
    cin >> prn;
    cout << "Enter Name: ";
    cin.ignore(); // Clear the newline from the input buffer
    getline(cin, name);
    club.addMember(prn, name);
}

int main() {
    PinnacleClub divisionA;
    PinnacleClub divisionB;
    int choice;

    do {
        cout << "\nPinnacle Club Menu:\n";
        cout << "1. Add Member to Division A\n";
        cout << "2. Add Member to Division B\n";
        cout << "3. Delete Member from Division A\n";
        cout << "4. Delete Member from Division B\n";
        cout << "5. Display Members of Division A\n";
        cout << "6. Display Members of Division B\n";
        cout << "7. Compute Total Members in Division A\n";
        cout << "8. Compute Total Members in Division B\n";
        cout << "9. Concatenate Division B into Division A\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMemberInput(divisionA);
                break;
            case 2:
                addMemberInput(divisionB);
                break;
            case 3: {
                string prn;
                cout << "Enter PRN of the member to delete from Division A: ";
                cin >> prn;
                divisionA.deleteMember(prn);
                break;
            }
            case 4: {
                string prn;
                cout << "Enter PRN of the member to delete from Division B: ";
                cin >> prn;
                divisionB.deleteMember(prn);
                break;
            }
            case 5:
                cout << "\nMembers of Division A:\n";
                divisionA.displayMembers();
                break;
            case 6:
                cout << "\nMembers of Division B:\n";
                divisionB.displayMembers();
                break;
            case 7:
                cout << "Total members in Division A: " << divisionA.totalMembers() << endl;
                break;
            case 8:
                cout << "Total members in Division B: " << divisionB.totalMembers() << endl;
                break;
            case 9:
                cout << "Concatenating Division B into Division A..." << endl;
                divisionA.concatenate(divisionB);
                cout << "Concatenation complete." << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
