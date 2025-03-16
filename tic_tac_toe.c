// Created by: Ratna Kirti
// Finals: Question 1

#include <stdio.h>  // Include standard input/output library
#include <stdlib.h>  // Include standard library
#include <time.h>   // Include time library

#define SIZE 10          // Define the size of the game board
#define WIN_CONDITION 5  // Define the number of pieces in a row to win

// Function to print the game board
void printBoard(char grid[SIZE][SIZE]) {
    printf("   "); // Print leading spaces
    for (int j = 0; j < SIZE; j++) { 
        printf("%2d", j); // Printing with formatting column numbers
    }
    printf("\n"); 

    for (int i = SIZE - 1; i >= 0; i--) { // Loop through rows in reverse order
        printf("%2d ", i); // Printing with formatting row numbers
        for (int j = 0; j < SIZE; j++) { 
            printf("%c ", grid[i][j]); // Print the character at the current cell
        }
        printf("\n"); 
    }
}

// Function to check for win condition
int checkWin(char grid[SIZE][SIZE], int row, int col, char player) {
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}}; // Define the four directions to check for win
    for (int d = 0; d < 4; d++) { // Iterating through the four directions
        int count = 1; 
        for (int i = 1; i < WIN_CONDITION; i++) { // Check forward in the current direction
            int newRow = row + i * directions[d][0]; // Calculate new row coordinate
            int newCol = col + i * directions[d][1]; // Calculate new column coordinate
            if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE && grid[newRow][newCol] == player) { // Verify if within bounds and matches player
                count++; // Increase count when match is found
            } else {
                break; // Stop checking in this direction if no match or out of bounds
            }
        }
        for (int i = 1; i < WIN_CONDITION; i++) { // Check backward in the current direction
            int newRow = row - i * directions[d][0]; // Calculate new row coordinate
            int newCol = col - i * directions[d][1]; // Calculate new column coordinate
            if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE && grid[newRow][newCol] == player) { // Check if within bounds and matches player
                count++; // Increase count when match is found
            } else {
                break; // Stop checking in this direction if no match or out of bounds
            }
        }
        if (count >= WIN_CONDITION) { // Check if win condition is met
            return 1; 
        }
    }
    return 0; // Return 0 if win condition is not met
}

// Function to get a input from the player
void getPlayerMove(int *row, int *col) {
    printf("Enter row and column (e.g., 9 0): "); 
    while (scanf("%d %d", row, col) != 2) { 
        while (getchar() != '\n'); // Clear input buffer
        printf("Enter row and column (e.g., 9 0): "); // Prompt for player input again
    }
}

// Function to get a move from the computer
void getComputerMove(char grid[SIZE][SIZE], int *row, int *col) {
    do {
        *row = rand() % SIZE; // Generate random row
        *col = rand() % SIZE; // Generate random column
    } while (grid[*row][*col] != '.'); // Repeat if the cell is not empty
}

// Function to play the game
void playGame(int vsComputer) {
    char grid[SIZE][SIZE]; // Declare the game grid
    for (int i = 0; i < SIZE; i++) { // Initialize the grid with empty cells ('.')
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    int moves = 0; // Initialize move counter
    int currentPlayer = 0; // Initialize current player (0 or 1)

    while (moves < SIZE * SIZE) { // Continue until the grid is full
        printBoard(grid); // Printing the current grid
        printf("Player %d's turn.\n", currentPlayer); // Prompt for player input with a newline

        int row, col; 
        if (vsComputer && currentPlayer == 1) { 
            getComputerMove(grid, &row, &col); 
        } else {
            getPlayerMove(&row, &col); // Get move from player
        }

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || grid[row][col] != '.') { // Check for valid move
            continue; 
        }

        grid[row][col] = currentPlayer + '0'; // Place the player's piece on the grid
        moves++; 

        if (checkWin(grid, row, col, currentPlayer + '0')) { // Check for win condition
            printBoard(grid); // Printing the final grid
            printf("%d VICTORIOUS\n", currentPlayer); // Printing the winning player
            return; 
        }

        currentPlayer = 1 - currentPlayer; // Switch to next player
    }

    printBoard(grid); // Printing the final grid
    printf("Draw\n"); // Printing draw message
}

int main() {
    srand(time(NULL)); // Seeding the random number generator

    int choice; // Declaring variable for menu choice
    while (1) { // Loop until a valid choice is made
        printf("Game Menu:\n"); 
        printf("1. vs Computer\n"); 
        printf("2. 2 Player\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); // Read menu choice

        if (choice == 1) { 
            playGame(1); // Play vs computer
            break; 
        } else if (choice == 2) { 
            playGame(0); // Play 2 player
            break; 
        } else {
            printf("Invalid choice. Try Again.\n"); // Print invalid choice message
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    return 0; 
}