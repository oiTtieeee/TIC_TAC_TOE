#include <iostream>
#include <vector>
using namespace std;

const char PLAYER = 'X';
const char COMPUTER = 'O';
const char EMPTY = ' ';

void drawBoard(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if (i % 3 != 2) cout << "|";
        if (i % 3 == 2 && i != 8)
            cout << "\n---+---+---\n";
    }
    cout << "\n\n";
}

bool isWinner(const vector<char>& b, char p) {
    int w[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for (auto &x : w)
        if (b[x[0]] == p && b[x[1]] == p && b[x[2]] == p)
            return true;
    return false;
}

bool isFull(const vector<char>& board) {
    for (char c : board)
        if (c == EMPTY) return false;
    return true;
}

int findBestMove(vector<char>& board, char p) {
    int w[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (auto &x : w) {
        int count = 0, empty = -1;
        for (int i : x) {
            if (board[i] == p) count++;
            if (board[i] == EMPTY) empty = i;
        }
        if (count == 2 && empty != -1)
            return empty;
    }
    return -1;
}

int computerMove(vector<char>& board) {
    int move;

    // 1. Win if possible
    move = findBestMove(board, COMPUTER);
    if (move != -1) return move;

    // 2. Block player
    move = findBestMove(board, PLAYER);
    if (move != -1) return move;

    // 3. Take center
    if (board[4] == EMPTY) return 4;

    // 4. Take corner
    int corners[] = {0,2,6,8};
    for (int c : corners)
        if (board[c] == EMPTY) return c;

    // 5. Take any side
    int sides[] = {1,3,5,7};
    for (int s : sides)
        if (board[s] == EMPTY) return s;

    return -1;
}

int main() {
    vector<char> board(9, EMPTY);
    int move;

    cout << "Tic Tac Toe (You = X, Computer = O)\n";
    drawBoard(board);

    while (true) {
        // Player move
        cout << "Enter position (1-9): ";
        cin >> move;
        move--;

        if (move < 0 || move > 8 || board[move] != EMPTY) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move] = PLAYER;
        drawBoard(board);

        if (isWinner(board, PLAYER)) {
            cout << "You win!\n";
            break;
        }

        if (isFull(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // Computer move
        int compMove = computerMove(board);
        board[compMove] = COMPUTER;
        cout << "Computer chose position " << compMove + 1 << "\n";
        drawBoard(board);

        if (isWinner(board, COMPUTER)) {
            cout << "Computer wins!\n";
            break;
        }

        if (isFull(board)) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
