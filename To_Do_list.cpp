#include <iostream>
#include <vector>
using namespace std;

struct Task
{
  string description;
  bool isCompleted;

  Task(const string &desc) : description(desc), isCompleted(false) {}
};

class ToDoList
{
private:
  vector<Task> tasks;

public:
  void addTask(const string &description)
  {
    tasks.push_back(Task(description));
    std::cout << "Task added: " << description << endl;
  }

  void displayTasks()
  {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++)
    {
      cout << (i + 1) << ". ";
      if (tasks[i].isCompleted)
        cout << "[X] ";
      else
        cout << "[ ] ";
      cout << tasks[i].description << endl;
    }
  }

  void markTaskCompleted(int taskIndex)
  {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size()))
    {
      tasks[taskIndex - 1].isCompleted = true;
      cout << "Task marked as completed: " << tasks[taskIndex - 1].description << endl;
    }
    else
    {
      cout << "Invalid task number." << endl;
    }
  }

  void removeTask(int taskIndex)
  {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size()))
    {
      cout << "Task removed: " << tasks[taskIndex - 1].description << endl;
      tasks.erase(tasks.begin() + taskIndex - 1);
    }
    else
    {
      cout << "Invalid task number." << endl;
    }
  }
};

int main()
{
  ToDoList toDoList;

  while (true)
  {
    cout << "Options:" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Display tasks" << endl;
    cout << "3. Mark a task as completed" << endl;
    cout << "4. Remove a task" << endl;
    cout << "5. Quit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
      string taskDescription;
      cout << "Enter task description: ";
      cin.ignore(); // Consume the newline character
      getline(cin, taskDescription);
      toDoList.addTask(taskDescription);
    }
    else if (choice == 2)
    {
      toDoList.displayTasks();
    }
    else if (choice == 3)
    {
      int taskIndex;
      cout << "Select the Task to mark as completed: ";
      cin >> taskIndex;
      toDoList.markTaskCompleted(taskIndex);
    }
    else if (choice == 4)
    {
      int taskIndex;
      cout << "Select the task to remove: ";
      cin >> taskIndex;
      toDoList.removeTask(taskIndex);
    }
    else if (choice == 5)
    {
      break;
    }
    else
    {
      cout << "Invalid choice!!! " << endl;
      cout << "Please try again." << endl;
    }
  }

  return 0;
}
