#include <iostream>
#include <vector>
#include <iomanip>

// Structure to represent a task
struct Task {
    std::string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(std::vector<Task> &tasks);
void viewTasks(const std::vector<Task> &tasks);
void markAsCompleted(std::vector<Task> &tasks);
void removeTask(std::vector<Task> &tasks);

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the to-do list manager." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    std::cout << "\n========== To-Do List Manager ==========" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void addTask(std::vector<Task> &tasks) {
    Task newTask;
    std::cout << "Enter the description of the task: ";
    std::cin.ignore();
    std::getline(std::cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added successfully." << std::endl;
}

void viewTasks(const std::vector<Task> &tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
    } else {
        std::cout << "\n========== Task List ==========" << std::endl;
        std::cout << std::setw(3) << "ID" << std::setw(20) << "Description" << std::setw(15) << "Status" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << std::setw(3) << i + 1 << std::setw(20) << tasks[i].description;
            std::cout << std::setw(15) << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
        }
    }
}

void markAsCompleted(std::vector<Task> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        int taskIndex;
        std::cout << "Enter the ID of the task to mark as completed: ";
        std::cin >> taskIndex;

        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task ID." << std::endl;
        }
    }
}

void removeTask(std::vector<Task> &tasks) {
    viewTasks(tasks);
    if (!tasks.empty()) {
        int taskIndex;
        std::cout << "Enter the ID of the task to remove: ";
        std::cin >> taskIndex;

        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task removed successfully." << std::endl;
        } else {
            std::cout << "Invalid task ID." << std::endl;
        }
    }
}
