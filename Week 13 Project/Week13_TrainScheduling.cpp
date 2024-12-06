#include <iostream>
#include <queue>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void loadQueue(queue<string>& q, const string& filename);
void saveQueue(queue<string>& q, const string& filename);
void loadStack(stack<string>& s, const string& filename);
void saveStack(stack<string>& s, const string& filename);
void displayQueue(queue<string> q);
void displayStack(stack<string> s);

int main() {
    queue<string> trainQueue;
    stack<string> completedRoutes;
    string trainQueueFile = "train_queue.txt";
    string completedRoutesFile = "completed_routes.txt";

    // Load previous state from files
    loadQueue(trainQueue, trainQueueFile);
    loadStack(completedRoutes, completedRoutesFile);

    int choice;
    do {
        cout << "\n--- Train Scheduling System ---\n";
        cout << "1. Add Train to Schedule\n";
        cout << "2. View Next Train\n";
        cout << "3. Complete Train Route\n";
        cout << "4. View Completed Routes\n";
        cout << "5. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // To handle trailing newline character
        switch (choice) {
            case 1: {
                string train;
                cout << "Enter train details: ";
                getline(cin, train);
                trainQueue.push(train);
                cout << "Train added to schedule.\n";
                break;
            }
            case 2: {
                if (!trainQueue.empty()) {
                    cout << "Next train in schedule: " << trainQueue.front() << "\n";
                } else {
                    cout << "No trains in the schedule.\n";
                }
                break;
            }
            case 3: {
                if (!trainQueue.empty()) {
                    string completedTrain = trainQueue.front();
                    trainQueue.pop();
                    completedRoutes.push(completedTrain);
                    cout << "Train completed: " << completedTrain << "\n";
                } else {
                    cout << "No trains to complete.\n";
                }
                break;
            }
            case 4: {
                if (!completedRoutes.empty()) {
                    cout << "Completed train routes:\n";
                    displayStack(completedRoutes);
                } else {
                    cout << "No completed routes.\n";
                }
                break;
            }
            case 5: {
                saveQueue(trainQueue, trainQueueFile);
                saveStack(completedRoutes, completedRoutesFile);
                cout << "Data saved. Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to load a queue from a file
void loadQueue(queue<string>& q, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            q.push(line);
        }
        file.close();
    }
}

// Function to save a queue to a file
void saveQueue(queue<string>& q, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        while (!q.empty()) {
            file << q.front() << "\n";
            q.pop();
        }
        file.close();
    }
}

// Function to load a stack from a file
void loadStack(stack<string>& s, const string& filename) {
    ifstream file(filename);
    stack<string> tempStack;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            tempStack.push(line);
        }
        file.close();
    }
    // Reverse the order to maintain the original stack structure
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Function to save a stack to a file
void saveStack(stack<string>& s, const string& filename) {
    ofstream file(filename);
    stack<string> tempStack;
    while (!s.empty()) {
        tempStack.push(s.top());
        s.pop();
    }
    if (file.is_open()) {
        while (!tempStack.empty()) {
            file << tempStack.top() << "\n";
            tempStack.pop();
        }
        file.close();
    }
}

// Function to display a queue
void displayQueue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << "\n";
        q.pop();
    }
}

// Function to display a stack
void displayStack(stack<string> s) {
    while (!s.empty()) {
        cout << s.top() << "\n";
        s.pop();
    }
}
