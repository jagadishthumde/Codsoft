#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool is_completed;
};

void addTask(std::vector<Task>& tasks) {
    Task new_task;
    std::cout << "Enter the task description: ";
    std::cin.ignore();
    std::getline(std::cin, new_task.description);
    new_task.is_completed = false;
    tasks.push_back(new_task);
    std::cout << "Task added successfully!" << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list." << std::endl;
    } else {
        std::cout << "Your Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].is_completed ? "Completed" : "Pending") << "]" 
                      << std::endl;
        }
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list to mark as completed." << std::endl;
        return;
    }

    size_t task_number;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> task_number;

    if (task_number > 0 && task_number <= tasks.size()) {
        tasks[task_number - 1].is_completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list to remove." << std::endl;
        return;
    }

    size_t task_number;
    std::cout << "Enter the task number to remove: ";
    std::cin >> task_number;

    if (task_number > 0 && task_number <= tasks.size()) {
        tasks.erase(tasks.begin() + task_number - 1);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting To-Do List Manager. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

