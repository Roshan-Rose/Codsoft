#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

vector<Task> tasks;

void addTask() {
    string desc;
    cin.ignore();  // To clear input buffer
    cout << "Enter task description: ";
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
    }
    cout << "\n";
}

void markCompleted() {
    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask() {
    int index;
    cout << "Enter the task number to delete: ";
    cin >> index;

    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void showMenu() {
    cout << "\n===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Exiting To-Do List Manager. Goodbye!\n"; break;
            default: cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
