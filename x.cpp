#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>

using namespace std;

// Stores each task and its priority number
struct TodoItem
{
    string task;
    int priority;

    // Used to create a new task with a priority
    TodoItem(string taskName, int taskPriority)
    {
        task = taskName;
        priority = taskPriority;
    }
};


// CHALLENGE 1
// Gets the current date and time
void displayDateTime()
{
    time_t currentTime = time(0);

    cout << "Current date and time: ";
    cout << ctime(&currentTime);
}


// Shows everything currently in the TODO list
void displayList(vector<TodoItem>& todoList)
{
    cout << "\n-------- TO-DO LIST --------\n";

    // Checks if there are no tasks in the list
    if (todoList.empty())
    {
        cout << "Your to-do list is empty.\n";
    }
    else
    {
        // CHALLENGE 1
        // Shows the date and time when the list is displayed
        displayDateTime();

        cout << "\n";

        // Goes through every task in the list
        for (int i = 0; i < todoList.size(); i++)
        {
            cout << "Priority " << todoList[i].priority
                 << ": " << todoList[i].task << endl;
        }
    }

    cout << "-----------------------------------\n";
}


// CHALLENGE 4
// Checks if a priority number is already being used
// This makes sure two tasks cannot have the same priority
bool priorityExists(vector<TodoItem>& todoList, int priority)
{
    // Check every task in the list
    for (int i = 0; i < todoList.size(); i++)
    {
        if (todoList[i].priority == priority)
        {
            return true;
        }
    }

    return false;
}


// Adds a new task to the TODO list
void addTask(vector<TodoItem>& todoList)
{
    string taskName;
    int priority;

    // Clears the leftover enter key before using getline
    cin.ignore(256, '\n');

    cout << "\nEnter the task you would like to add: ";
    getline(cin, taskName);

    // Keep asking until the user enters a valid priority
    while (true)
    {
        cout << "Enter a priority number for this task: ";
        cin >> priority;

        // Priority numbers must be positive
        if (priority < 1)
        {
            cout << "Priority must be 1 or greater.\n";
        }

        // CHALLENGE 4
        // Makes sure the priority is not already being used
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

    // Adds the task to the vector
    todoList.push_back(TodoItem(taskName, priority));

    cout << "Task successfully added!\n";
}


// Removes an item based on its priority
void removeTask(vector<TodoItem>& todoList)
{
    int priority;

    // There is nothing to remove if the list is empty
    if (todoList.empty())
    {
        cout << "\nThere are no tasks to remove.\n";
        return;
    }

    // Show the list first so the user can see the priorities
    displayList(todoList);

    cout << "\nEnter the priority of the task you want to remove: ";
    cin >> priority;

    // Look through the list for the priority entered
    for (int i = 0; i < todoList.size(); i++)
    {
        if (todoList[i].priority == priority)
        {
            cout << "Removed: " << todoList[i].task << endl;

            // Removes the task from the vector
            todoList.erase(todoList.begin() + i);

            return;
        }
    }

    cout << "No task with that priority was found.\n";
}


// CHALLENGE 3
// Sorts the TODO list alphabetically
// reverseOrder decides whether it sorts A-Z or Z-A
void sortAlphabetically(vector<TodoItem>& todoList, bool reverseOrder)
{
    // CHALLENGE 3a and 3b
    // This is a bubble sort made without using sort()
    for (int i = 0; i < todoList.size() - 1; i++)
    {
        for (int j = 0; j < todoList.size() - 1 - i; j++)
        {
            bool shouldSwap = false;

            // CHALLENGE 3a
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
                // CHALLENGE 3b
                // Sort from Z to A
                if (todoList[j].task < todoList[j + 1].task)
                {
                    shouldSwap = true;
                }
            }

            // Switch the two tasks if they are in the wrong order
            if (shouldSwap)
            {
                TodoItem temporary = todoList[j];
                todoList[j] = todoList[j + 1];
                todoList[j + 1] = temporary;
            }
        }
    }

    // Tell the user which type of sorting was done
    if (reverseOrder == false)
    {
        cout << "\nThe list has been sorted alphabetically.\n";
    }
    else
    {
        cout << "\nThe list has been sorted in reverse alphabetical order.\n";
    }
}


// CHALLENGE 4
// Sorts the TODO list from lowest priority number to highest
void sortByPriority(vector<TodoItem>& todoList)
{
    // Uses bubble sort to compare the priority numbers
    for (int i = 0; i < todoList.size() - 1; i++)
    {
        for (int j = 0; j < todoList.size() - 1 - i; j++)
        {
            // Move the larger priority number further down the list
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


// Gives the user different ways to sort the list
void sortingMenu(vector<TodoItem>& todoList)
{
    char choice;

    cout << "\n------ SORT MENU ------\n";
    cout << "A. Alphabetical (A-Z)\n";
    cout << "B. Reverse Alphabetical (Z-A)\n";
    cout << "C. Priority\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Allows the user to enter lowercase letters
    choice = toupper(choice);

    if (choice == 'A')
    {
        // CHALLENGE 3a
        sortAlphabetically(todoList, false);
    }
    else if (choice == 'B')
    {
        // CHALLENGE 3b
        sortAlphabetically(todoList, true);
    }
    else if (choice == 'C')
    {
        // CHALLENGE 4
        sortByPriority(todoList);
    }
    else
    {
        cout << "Invalid sorting option.\n";
    }
}


// Resets the current TODO list
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
        // Removes all tasks from the vector
        todoList.clear();

        int numberOfTasks;

        cout << "\nYour list has been reset.\n";
        cout << "How many tasks would you like to start your new list with? ";
        cin >> numberOfTasks;

        // Makes sure the number of tasks is not negative
        while (numberOfTasks < 0)
        {
            cout << "Please enter 0 or a positive number: ";
            cin >> numberOfTasks;
        }

        // Add the number of tasks chosen by the user
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


// CHALLENGE 2
// Loads the TODO list from a text file
bool loadList(vector<TodoItem>& todoList)
{
    ifstream inputFile("todoList.txt");

    // If the file cannot be opened, return false
    if (!inputFile.is_open())
    {
        return false;
    }

    string taskName;
    int priority;

    // Each task is stored as two lines in the file:
    // First line = task name
    // Second line = priority
    while (getline(inputFile, taskName))
    {
        if (inputFile >> priority)
        {
            // Clears the leftover enter key
            inputFile.ignore(1000, '\n');

            // Add the task that was read from the file
            todoList.push_back(TodoItem(taskName, priority));
        }
    }

    inputFile.close();

    return true;
}


// CHALLENGE 2
// Saves the TODO list to a text file
void saveList(vector<TodoItem>& todoList)
{
    ofstream outputFile("todoList.txt");

    // Check if the file opened correctly
    if (!outputFile.is_open())
    {
        cout << "There was an error saving the TODO list.\n";
        return;
    }

    // Write each task and its priority to the file
    for (int i = 0; i < todoList.size(); i++)
    {
        outputFile << todoList[i].task << endl;
        outputFile << todoList[i].priority << endl;
    }

    outputFile.close();

    cout << "\nTODO list saved successfully.\n";
}


// Creates the starting TODO list
void createStartingList(vector<TodoItem>& todoList)
{
    int numberOfTasks;

    cout << "\nHow many items would you like to start with? ";
    cin >> numberOfTasks;

    // Makes sure the number of tasks is not negative
    while (numberOfTasks < 0)
    {
        cout << "Please enter 0 or a positive number: ";
        cin >> numberOfTasks;
    }

    // Adds the number of tasks entered by the user
    for (int i = 0; i < numberOfTasks; i++)
    {
        cout << "\nAdding task " << i + 1 << " of "
             << numberOfTasks << endl;

        addTask(todoList);
    }
}


// Displays the main menu
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

    // Converts lowercase input into uppercase
    return toupper(choice);
}


// Does the action chosen from the main menu
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
    // Creates the vector that will hold all TODO items
    vector<TodoItem> todoList;

    char loadChoice;

    cout << "-------------------------------------\n";
    cout << "        TO-DO LIST PROGRAM\n";
    cout << "-------------------------------------\n";

    // Ask the user if they want to load a previous list
    cout << "\nWould you like to load a previous TODO list?\n";
    cout << "Enter Y for yes or N for no: ";
    cin >> loadChoice;

    loadChoice = toupper(loadChoice);

    // CHALLENGE 2
    // Try to load the previous list from the text file
    if (loadChoice == 'Y')
    {
        if (loadList(todoList))
        {
            cout << "\nYour previous TODO list was loaded successfully.";
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

    // Keep showing the menu until the user chooses to exit
    while (finished == false)
    {
        finished = performAction(todoList);
    }

    // CHALLENGE 2
    // The file is only written once when the program ends.
    saveList(todoList);
}