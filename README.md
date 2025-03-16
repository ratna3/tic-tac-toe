# Tic-Tac-Toe Game

## Description

This is a C program that implements a generalized version of the classic children's game Tic-Tac-Toe. The game is played on a 10x10 board. The two players (Player 0 and Player 1) alternate placing their number on unoccupied cells of the board until one of them achieves 5 in a row (horizontally, vertically, or diagonally). If the board is filled without either player winning, the game is declared a draw.

## Features

- Two game modes: Player vs Computer and Player vs Player.
- The game board is displayed after each move.
- Input validation to ensure moves are within the bounds of the board and on unoccupied cells.
- The game checks for a win condition after each move.

## How to Play

1. Run the program.
2. Choose the game mode:
   - Enter `1` to play against the computer.
   - Enter `2` to play against another player.
3. The game will prompt the current player to enter their move in the format `row column` (e.g., `9 0`).
4. The game will display the updated board after each move.
5. The game continues until one player achieves 5 in a row or the board is filled.
6. The game will display the winner or declare a draw if the board is filled without a winner.

## Code Structure

- `printBoard`: Function to print the current state of the game board.
- `checkWin`: Function to check if a player has won the game.
- `getPlayerMove`: Function to get a move from the player.
- `getComputerMove`: Function to get a move from the computer.
- `playGame`: Function to play the game.
- `main`: Main function to start the game and handle the game menu.

