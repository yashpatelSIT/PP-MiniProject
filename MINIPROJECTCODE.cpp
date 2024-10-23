#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class
class Task {
protected:
    string subject;
    string date;

public:
    // Constructor for base class
    Task(string subj, string dt) : subject(subj), date(dt) {}

    // Virtual function for displaying the task (to be overridden by derived classes)
    virtual void display() = 0; // Pure virtual function (polymorphism)
};

// Derived class for assignments
class Assignment : public Task {
private:
    string description;

public:
    // Constructor for assignment class
    Assignment(string subj, string dt, string desc)
        : Task(subj, dt), description(desc) {}

    // Overriding the display function for assignments
    void display() override {
        cout << "Assignment:\n";
        cout << "  Subject: " << subject << "\n";
        cout << "  Due Date: " << date << "\n";
        cout << "  Description: " << description << "\n";
    }
};

// Function to display the menu
void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add Assignment\n";
    cout << "2. Print Timetable\n";
    cout << "3. Exit\n";
}

int main() {
    vector<Task*> tasks; // Vector of Task pointers for polymorphism
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) { // Add assignment
            string subject, dueDate, description;
            cout << "Enter subject: ";
            cin.ignore(); // Clear the newline from input buffer
            getline(cin, subject);
            cout << "Enter due date (dd/mm/yyyy): ";
            getline(cin, dueDate);
            cout << "Enter description: ";
            getline(cin, description);
            // Add new assignment to the vector
            tasks.push_back(new Assignment(subject, dueDate, description));

        } else if (choice == 2) { // Print timetable
            if (tasks.empty()) {
                cout << "No tasks added yet.\n";
            } else {
                for (auto task : tasks) {
                    task->display(); // Polymorphism in action
                    cout << "-----------------\n";
                }
            }

        } else if (choice == 3) { // Exit the program
            // Clean up dynamic memory
            for (auto task : tasks) {
                delete task;
            }
            tasks.clear();
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
