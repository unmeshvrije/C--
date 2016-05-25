#include<iostream>

using namespace std;

/**
 * 1. Insert
 * 2. Delete
 * 3. Replace
 *
 *        i
 * algorithm
 *        j
 *  aphorism
 * */

int min (int a, int b, int c) {
  return min(min(a,b), c);
}

int editDistance(string& s1, string& s2, int i, int j) {
  if (i == 0) { // Source string is empty: add all characters from dest
    return j;
  }

  if (j == 0) { // Destination string is empty, remove all characters from source
    return i;
  }

  if (s1[i-1] == s2[j-1]) {
    return editDistance(s1, s2, i-1, j-1);
  }

  return 1 + min (editDistance(s1, s2, i, j-1), // Insert,
                  editDistance(s1, s2, i-1,j), // Delete,
                  editDistance(s1, s2, i-1, j-1));

}

int editDistanceDp(string& s1, string& s2, int m, int n) {
  int dp[m+1][n+1];

  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        dp[i][j] = 1 + min (dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
      }
    }
  }
  return dp[m][n];
}

int main(int argc, char *argv[]) {
  string s1 = argv[1];
  string s2 = argv[2];

  cout << s1 << endl;
  cout << s2 << endl;
  
  cout << editDistance(s1, s2, s1.size(), s2.size()) << endl;
  cout << editDistanceDp(s1, s2, s1.size(), s2.size()) << endl;
  return 0;
}
