#include <iostream>
#include <vector>

// Function prototypes
void initializeBoard(std::vector<std::vector<char>> &board);
void displayBoard(const std::vector<std::vector<char>> &board);
bool makeMove(std::vector<std::vector<char>> &board, char currentPlayer);
bool checkForWin(const std::vector<std::vector<char>> &board, char currentPlayer);
bool checkForDraw(const std::vector<std::vector<char>> &board);
void switchPlayer(char &currentPlayer);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;
    bool wantToPlayAgain = true;

    while (wantToPlayAgain) {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

        initializeBoard(board);

        while (!gameOver) {
            displayBoard(board);
            gameOver = makeMove(board, currentPlayer);

            if (checkForWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }

            if (checkForDraw(board)) {
                displayBoard(board);
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            switchPlayer(currentPlayer);
        }

        wantToPlayAgain = playAgain();
        gameOver = false;
    }

    std::cout << "Thanks for playing Tic-Tac-Toe!" << std::endl;

    return 0;
}

void initializeBoard(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>> &board) {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool makeMove(std::vector<std::vector<char>> &board, char currentPlayer) {
    int row, col;

    std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    std::cin >> row >> col;

    // Adjusting for zero-based indexing
    --row;
    --col;

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return false;  // Game not over
    } else {
        std::cout << "Invalid move. Try again." << std::endl;
        return makeMove(board, currentPlayer);  // Recursive call to get a valid move
    }
}

bool checkForWin(const std::vector<std::vector<char>> &board, char currentPlayer) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;  // Row win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;  // Column win
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;  // Diagonal win (top-right to bottom-left)
    }

    return false;
}

bool checkForDraw(const std::vector<std::vector<char>> &board) {
    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;  // Board is not full
            }
        }
    }
    return true;  // Board is full, and there is no winner
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char response;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}
