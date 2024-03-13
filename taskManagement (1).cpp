#include <iostream>
#include <string>


class Task {
public:
    std::string name;
    std::string description;
    std::string dueDate;
};

struct Node {
    Task task;
    Node* next;
};

// TaskManager class
class TaskManager {
private:
    Node* head;

public:
    TaskManager() {
        head = nullptr; 
    }

    //add a task 
    void addTask(const Task& task) {
        Node* newNode = new Node;
        newNode->task = task;
        newNode->next = head;
        head = newNode;
    }

    //remove a task
    void removeTask(const std::string& taskName) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->task.name == taskName) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return; 
            }

            prev = current;
            current = current->next;
        }
        std::cout << "Task not found." << std::endl;
    }

    //list all tasks
    void listTasks() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Task: " << current->task.name << std::endl;
            std::cout << "Description: " << current->task.description << std::endl;
            std::cout << "Due Date: " << current->task.dueDate << std::endl;
            std::cout << "--------------------------" << std::endl;
            current = current->next;
        }
    }

    // Destructor
    ~TaskManager() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    TaskManager taskManager; 

    int choice;

    do {
        std::cout << "Task Manager Menu" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Remove Task" << std::endl;
        std::cout << "3. List Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Task task;
                std::cin.ignore(); // Clear the newline character from the previous input
                std::cout << "Enter Task Name: ";
                std::getline(std::cin, task.name);
                std::cout << "Enter Task Description: ";
                std::getline(std::cin, task.description);
                std::cout << "Enter Due Date: ";
                std::getline(std::cin, task.dueDate);
                taskManager.addTask(task);
                break;
            }
            case 2: {
                std::string taskName;
                std::cin.ignore(); // Clear the newline character from the previous input
                std::cout << "Enter the Task Name to Remove: ";
                std::getline(std::cin, taskName);
                taskManager.removeTask(taskName);
                break;
            }
            case 3:
                std::cout << "List of Tasks:" << std::endl;
                taskManager.listTasks();
                break;
            case 4:
                std::cout << "Exiting the Task Manager. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option (1-4)." << std::endl;
        }

    } while (choice != 4);

    return 0;
}