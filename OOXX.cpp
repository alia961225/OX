#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void initializeBoard(vector<vector<char> > &board);
void printBoard(const vector<vector<char> > &board);
bool makeMove(vector<vector<char> > &board, char player, int move);
bool checkWin(const vector<vector<char> > &board, char player);
bool checkTie(const vector<vector<char> > &board);
int getComputerMove(const vector<vector<char> > &board);
int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char humanPlayer = 'X';
    char computerPlayer = 'O';
    cout << "歡迎來玩圈圈叉叉遊戲！" << endl;
    while (true) {
        printBoard(board);
        int move;
        cout << "請玩家 " << humanPlayer << " 選擇位置 (1-9): ";
        cin >> move;
        if (makeMove(board, humanPlayer, move)) {
            if (checkWin(board, humanPlayer)) {
                printBoard(board);
                cout << "玩家 " << humanPlayer << " 獲勝！" << endl;
                break;
            } else if (checkTie(board)) {
                printBoard(board);
                cout << "平局！" << endl;
                break;
            }
        } else {
            cout << "無效的位置，請重新輸入。" << endl;
            continue;
        }
        int computerMove = getComputerMove(board);
        cout << "電腦選擇位置: " << computerMove << endl;
        if (makeMove(board, computerPlayer, computerMove)) {
            if (checkWin(board, computerPlayer)) {
                printBoard(board);
                cout << "電腦獲勝！" << endl;
                break;
            } else if (checkTie(board)) {
                printBoard(board);
                cout << "平局！" << endl;
                break;
            }
        } else {
            cout << "電腦選擇了無效的位置。" << endl;
        }
    }
    return 0;
}
void initializeBoard(vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}
void printBoard(const vector<vector<char> > &board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}
bool makeMove(vector<vector<char> > &board, char player, int move) {
    if (move < 1 || move > 9) {
        return false; 
    }
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}
bool checkWin(const vector<vector<char> > &board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}
bool checkTie(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
int getComputerMove(const vector<vector<char> > &board) {
    int move;
    do {
        move = rand() % 9 + 1; 
    } while (!makeMove(board, 'O', move)); 
    return move;
}
