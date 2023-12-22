#include <iostream>
#include <vector>
using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>> &board)
{
    cout << "-------------\n";
    for (const auto &row : board)
    {
        cout << "| " << row[0] << " | " << row[1] << " | " << row[2] << " |\n";
        cout << "-------------\n";
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true; // Player has won
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true; // Player has won
    }

    return false; // No winner yet
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false; // Board is not full
            }
        }
    }
    return true; // Board is full
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));

    int row, col;
    char currentPlayer = 'X';

    do
    {
        // Print the current state of the board
        printBoard(board);

        // Get player move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer))
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check if the board is full (tie)
        if (isBoardFull(board))
        {
            printBoard(board);
            cout << "It's a tie!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}
