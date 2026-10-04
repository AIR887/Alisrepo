#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>

using namespace std;

// stores each task and its priority number
struct TodoItem
{
    string task;
    int priority;

    // used to create a new task with a priority
    TodoItem(string taskName, int taskPriority)
    {
        task = taskName;
        priority = taskPriority;
    }
};


// Challenge 1
// current date and time
void displayDateTime()
{
    time_t currentTime = time(0);

    cout << "Current date and time: ";
    cout << ctime(&currentTime);
}


// shows everything currently in the todo list
void displayList(vector<TodoItem>& todoList)
{
    cout << "\n-------- TO-DO LIST --------\n";

    // checks if there are no tasks in the list
    if (todoList.empty())
    {
        cout << "Your to-do list is empty.\n";
    }
    else
    {
        // Challenge 1
        // shows the date and time when the list is displayed
        displayDateTime();

        cout << "\n";

        // goes through every task in the list
        for (int i = 0; i < todoList.size(); i++)
        {
            cout << "Priority " << todoList[i].priority << ": " << todoList[i].task << endl;
        }
    }

    cout << "-----------------------------------\n";
}


// Challenge 4
// checks if a priority number is already being used
// makes sure two tasks cannot have the same priority
bool priorityExists(vector<TodoItem>& todoList, int priority)
{
    // check every task in the list
    for (int i = 0; i < todoList.size(); i++)
    {
        if (todoList[i].priority == priority)
        {
            return true;
        }
    }

    return false;
}


// add a new task to the todo list
void addTask(vector<TodoItem>& todoList)
{
    string taskName;
    int priority;

    cin.ignore(256, '\n');

    cout << "\nEnter the task you would like to add: ";
    getline(cin, taskName);

    // keep asking until the user enters a valid priority
    while (true)
    {
        cout << "Enter a priority number for this task: ";
        cin >> priority;

        // priority numbers must be positive
        if (priority < 1)
        {
            cout << "Priority must be 1 or greater.\n";
        }

        // Challenge 4
        // makes sure the priority is not already being used
        else if (priorityExists(todoList, priority))
        {
            cout << "That priority is already being used.\n";
            cout << "Please choose a different priority.\n";
        }
        else
        {
            break;
        }
    }

    todoList.push_back(TodoItem(taskName, priority));

    cout << "Task successfully added!\n";
}


// removes an item based on its priority
void removeTask(vector<TodoItem>& todoList)
{
    int priority;

    if (todoList.empty())
    {
        cout << "\nThere are no tasks to remove.\n";
        return;
    }

    // show the list first so the user can see the priorities
    displayList(todoList);

    cout << "\nEnter the priority of the task you want to remove: ";
    cin >> priority;

    // look through the list for the priority entered
    for (int i = 0; i < todoList.size(); i++)
    {
        if (todoList[i].priority == priority)
        {
            cout << "Removed: " << todoList[i].task << endl;

            // removes the task from the vector
            todoList.erase(todoList.begin() + i);

            return;
        }
    }

    cout << "No task with that priority was found.\n";
}


// Challenge 3
// sorts the todo list alphabetically
void sortAlphabetically(vector<TodoItem>& todoList, bool reverseOrder)
{
    // Challenge 3a and 3b
    for (int i = 0; i < todoList.size() - 1; i++)
    {
        for (int j = 0; j < todoList.size() - 1 - i; j++)
        {
            bool shouldSwap = false;

            // Challenge 3a
            // Sort from A to Z
            if (reverseOrder == false)
            {
                if (todoList[j].task > todoList[j + 1].task)
                {
                    shouldSwap = true;
                }
            }
            else
            {
                // Challenge 3b
                // Sort from Z to A
                if (todoList[j].task < todoList[j + 1].task)
                {
                    shouldSwap = true;
                }
            }

            // switch the two tasks if they are in the wrong order
            if (shouldSwap)
            {
                TodoItem temporary = todoList[j];
                todoList[j] = todoList[j + 1];
                todoList[j + 1] = temporary;
            }
        }
    }

    // tell the user which type of sorting was done
    if (reverseOrder == false)
    {
        cout << "\nThe list has been sorted alphabetically.\n";
    }
    else
    {
        cout << "\nThe list has been sorted in reverse alphabetical order.\n";
    }
}


// Challenge 4
// sorts the todo list from lowest priority to highest
void sortByPriority(vector<TodoItem>& todoList)
{
    // uses bubble sort to compare the priority numbers
    for (int i = 0; i < todoList.size() - 1; i++)
    {
        for (int j = 0; j < todoList.size() - 1 - i; j++)
        {
            // move the larger priority number down the list
            if (todoList[j].priority > todoList[j + 1].priority)
            {
                TodoItem temporary = todoList[j];
                todoList[j] = todoList[j + 1];
                todoList[j + 1] = temporary;
            }
        }
    }

    cout << "\nThe list has been sorted by priority.\n";
}


// gives the user different ways to sort the list
void sortingMenu(vector<TodoItem>& todoList)
{
    char choice;

    cout << "\n------ SORT MENU ------\n";
    cout << "A. Alphabetical (A-Z)\n";
    cout << "B. Reverse Alphabetical (Z-A)\n";
    cout << "C. Priority\n";
    cout << "Enter your choice: ";
    cin >> choice;

    choice = toupper(choice);

    if (choice == 'A')
    {
        sortAlphabetically(todoList, false);
    }
    else if (choice == 'B')
    {
        sortAlphabetically(todoList, true);
    }
    else if (choice == 'C')
    {
        sortByPriority(todoList);
    }
    else
    {
        cout << "Invalid sorting option.\n";
    }
}


// resets the todo list
void resetList(vector<TodoItem>& todoList)
{
    char confirmation;

    cout << "\nAre you sure you want to reset your entire list?\n";
    cout << "All current tasks will be removed.\n";
    cout << "Enter Y to continue or N to cancel: ";
    cin >> confirmation;

    confirmation = toupper(confirmation);

    if (confirmation == 'Y')
    {
        // removes all tasks from the vector
        todoList.clear();

        int numberOfTasks;

        cout << "\nYour list has been reset.\n";
        cout << "How many tasks would you like to start your new list with? ";
        cin >> numberOfTasks;

        // makes sure the number of tasks is not negative
        while (numberOfTasks < 0)
        {
            cout << "Please enter 0 or a positive number: ";
            cin >> numberOfTasks;
        }

        // add the number of tasks chosen by the user
        for (int i = 0; i < numberOfTasks; i++)
        {
            cout << "\nAdding task " << i + 1 << " of "
                 << numberOfTasks << endl;

            addTask(todoList);
        }
    }
    else
    {
        cout << "Reset cancelled.\n";
    }
}


// Challenge 2
// loads the todo list from a text file
bool loadList(vector<TodoItem>& todoList)
{
    ifstream inputFile("todoList.txt");

    // if the file cannot be opened it will return false
    if (!inputFile.is_open())
    {
        return false;
    }

    string taskName;
    int priority;

    // each task is stored as two lines in the file:
    // first line = task name
    // second line = priority
    while (getline(inputFile, taskName))
    {
        if (inputFile >> priority)
        {
            inputFile.ignore(256, '\n');

            // add the task that was read from the file
            todoList.push_back(TodoItem(taskName, priority));
        }
    }

    inputFile.close();

    return true;
}


// Challenge 2
// saves the todo list to a text file
void saveList(vector<TodoItem>& todoList)
{
    ofstream outputFile("todoList.txt");

    // check if the file opened correctly
    if (!outputFile.is_open())
    {
        cout << "There was an error saving the TODO list.\n";
        return;
    }

    // write each task and its priority to the file
    for (int i = 0; i < todoList.size(); i++)
    {
        outputFile << todoList[i].task << endl;
        outputFile << todoList[i].priority << endl;
    }

    outputFile.close();

    cout << "\nTODO list saved successfully.\n";
}


// creates the starting todo list
void createStartingList(vector<TodoItem>& todoList)
{
    int numberOfTasks;

    cout << "\nHow many items would you like to start with? ";
    cin >> numberOfTasks;

    // makes sure number of tasks is not negative
    while (numberOfTasks < 0)
    {
        cout << "Please enter 0 or a positive number: ";
        cin >> numberOfTasks;
    }

    // adds the number of tasks entered by the user
    for (int i = 0; i < numberOfTasks; i++)
    {
        cout << "\nAdding task " << i + 1 << " of "
             << numberOfTasks << endl;

        addTask(todoList);
    }
}


// main menu
char showMenu()
{
    char choice;

    cout << "\n\n---------------------------------\n";
    cout << "          TO-DO LIST MENU\n";
    cout << "----------------------------------\n";
    cout << "A. Add a task\n";
    cout << "B. Read the list\n";
    cout << "C. Remove a task\n";
    cout << "D. Sort the list\n";
    cout << "E. Reset the list\n";
    cout << "F. Exit\n";
    cout << "----------------------------------\n";
    cout << "Enter your choice: ";

    cin >> choice;

    return toupper(choice);
}


// does the action chosen from the menu
bool performAction(vector<TodoItem>& todoList)
{
    char choice = showMenu();

    if (choice == 'A')
    {
        addTask(todoList);
    }
    else if (choice == 'B')
    {
        displayList(todoList);
    }
    else if (choice == 'C')
    {
        removeTask(todoList);
    }
    else if (choice == 'D')
    {
        sortingMenu(todoList);
    }
    else if (choice == 'E')
    {
        resetList(todoList);
    }
    else if (choice == 'F')
    {
        cout << "\nExiting program...\n";
        return true;
    }
    else
    {
        cout << "\nInvalid menu option. Please choose A-F.\n";
    }

    return false;
}


int main()
{
    // creates the vector that will hold all todo items
    vector<TodoItem> todoList;

    char loadChoice;

    cout << "-------------------------------------\n";
    cout << "        TO-DO LIST PROGRAM\n";
    cout << "-------------------------------------\n";

    // ask user if they want to load a previous list
    cout << "\nWould you like to load a previous TODO list?\n";
    cout << "Enter Y for yes or N for no: ";
    cin >> loadChoice;

    loadChoice = toupper(loadChoice);

    // Challenge 2
    // load the previous list from the text file
    if (loadChoice == 'Y')
    {
        if (loadList(todoList))
        {
            cout << "\nYour previous TODO list was loaded.";
            displayList(todoList);
        }
        else
        {
            cout << "\nNo saved TODO list was found.\n";
            createStartingList(todoList);
        }
    }
    else
    {
        createStartingList(todoList);
    }

    bool finished = false;

    // keep showing the menu until the user exits
    while (finished == false)
    {
        finished = performAction(todoList);
    }

    // file is only written once when the program ends.
    saveList(todoList);
}