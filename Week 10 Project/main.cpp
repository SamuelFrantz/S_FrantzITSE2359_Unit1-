#include <iostream>
using namespace std;

// Function to print the maze with solution path
void printMaze(int** maze, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1) {
                cout << "# ";  // Wall
            } else if (maze[i][j] == 2) {
                cout << ". ";  // Solution path
            } else {
                cout << "  ";  // Open cell
            }
        }
        cout << endl;
    }
}

// Recursive function to solve the maze
bool solveMaze(int** maze, int x, int y, int height, int width) {
    // Check if (x, y) is out of bounds or a wall
    if (x < 0 || x >= height || y < 0 || y >= width || maze[x][y] != 0) {
        return false;
    }

    // Check if we've reached the end of the maze
    if (x == height - 1 && y == width - 1) {
        maze[x][y] = 2; // Mark the path
        return true;
    }

    // Mark current cell as part of the solution path
    maze[x][y] = 2;

    // Recursive calls: Move in each direction (right, down, left, up)
    if (solveMaze(maze, x, y + 1, height, width)) return true; // Right
    if (solveMaze(maze, x + 1, y, height, width)) return true; // Down
    if (solveMaze(maze, x, y - 1, height, width)) return true; // Left
    if (solveMaze(maze, x - 1, y, height, width)) return true; // Up

    // Backtrack: If no path is found, reset the cell to its original state
    maze[x][y] = 0;
    return false; // No solution found from this position
}

int main() {
    int width, height;

    // Get maze dimensions from the user
    cout << "Enter the height of the maze: ";
    cin >> height;
    cout << "Enter the width of the maze: ";
    cin >> width;

    // Dynamically allocate the maze based on user input
    int** maze = new int*[height];
    for (int i = 0; i < height; i++) {
        maze[i] = new int[width];
    }

    // Get maze configuration from the user
    cout << "Enter the maze configuration (0 for open, 1 for wall):" << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> maze[i][j];
        }
    }

    cout << "Initial Maze:" << endl;
    printMaze(maze, height, width);

    if (solveMaze(maze, 0, 0, height, width)) {
        cout << "Path found:\n";
    } else {
        cout << "No path found.\n";
    }
    printMaze(maze, height, width);

    // Free allocated memory
    for (int i = 0; i < height; i++) {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}
