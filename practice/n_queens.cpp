#include<iostream>
#include<vector>
#include<string>
#include<sys/time.h>
#include<cstring>

using namespace std;

void print_board(vector<string>& board) {
    for (int i = 0; i < board.size(); ++i) {
         cout << board[i] << endl;
    }
    cout << endl;
}

void init_board(vector<string>& board) {
  int n = board.size();
  for (int i = 0; i < n; ++i) {
    board[i] = string(n,'.');
  }
}


/**
 * Queens are only present on the left.
 * */
bool isSafe(vector<string>& board, int row, int col) {
  
  // Check this row until the col
  for (int i = 0; i < col; ++i) {
    if (board[row][i] == 'Q') {
      return false;
    }
  }

  // Check the upper diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--,j--) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  // Check the lower diagonal
  for (int i = row, j = col; i < board.size() && j >= 0; i++,j--) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  return true;
}

bool n_queens_util(vector<string>board, int n, int col, int& solutions) {

  // Base case: If all queens are placed, return true
  if (col >= n) {
    solutions++;
    print_board(board);
    return true;
  }

  // Consider the column 'col' and try placing
  // this queen in all rows one by one
  for (int i = 0; i < n; ++i) {

    // Check if the queen can be placed at [i][col] position
    if (isSafe(board, i, col)) {

      // Place this queen on the board
      board[i][col] = 'Q';

      // Recursively solve the problem for remaining board and next column
      if (!n_queens_util(board, n, col+1, solutions)) {
        // Remove the queen from the board /backtrack
        board[i][col] = '.';
      }

    }
  }

  return false;
}

int main(void) {
  int n;
  cout << "Enter n : ";
  cin >> n;

  string row(n, '.');
  vector<string> board = vector<string>(n);
  for (int i = 0; i < n; ++i) {
      board[i] = row;
  }

 // print_board(board);

 // nQueens(board, board.size());
  init_board(board);
  int solutions = 0;
  struct timeval start;
  memset(&start, 0, sizeof(start));
  struct timeval end;
  memset(&end, 0, sizeof(end));
  gettimeofday(&start, NULL);
  n_queens_util(board, board.size(), 0, solutions);
  gettimeofday(&end, NULL);

  long long elapsed = (end.tv_sec - start.tv_sec)*1000 + (end.tv_usec - start.tv_usec)/1000;
  cout << "N = " << n << endl;
  cout << "#(solutions) = " << solutions << endl;
  cout << "time = " << elapsed << "ms" << endl;
  return 0;
}
