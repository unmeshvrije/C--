#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

bool isPalindrome(string str)
{
  if (str.empty()) {
    return true;
  }
  int len = str.length();
  if (len == 1) {
    return true;
  }

  int i = 0;
  int j = len - 1;
  while (i <= j) {
    if (str[i] != str[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

string longestPalindrome(string str)
{
  string longestPal="";
  int len = str.size();
  int maxLength = INT_MIN;
  for (int i = 0; i < len; ++i) {
    for (int j = 1; j <= len - i; ++j) {
      // Substring starting from index i, of length j
      string pal = str.substr(i, j);
      if (isPalindrome(pal)) {
        if (j > maxLength) {
          maxLength = j;
          longestPal = pal;
        }
      }
    }
  }

  return longestPal;
}

string longestPalindrome_dp(string str)
{
  int len = str.size();
  bool table[len][len];
  // Initialize the table to false
  memset(table, 0, sizeof(table));

  int maxLength = 1;
  // Every string of length 1 is a palindrome
  for (int i = 0; i < len; ++i) {
    table[i][i] = true;
  }

  int start = 0;
  // Handle substrings of length 2
  for (int i = 0; i < len-1; ++i) {
    if (str[i] == str[i+1]) {
      table[i][i+1] = true;
      start = i;
      maxLength = 2;
    }
  }

  for (int k = 3; k <= len; ++k) {
    for (int i = 0; i < len-k+1; ++i) {
      int j = i + k -1;

      if (table[i+1][j-1] && str[i] == str[j]) {
        table[i][j] = true;
        if (k > maxLength) {
          maxLength = k;
          start = i;
        }
      }
    }
  }

  return str.substr(start, maxLength);
}


int main(int argc, char*argv[])
{
  string str = string(argv[1]);
  //cout << str << " is " << (!isPalindrome(str) ? "not" : "") << "a palindrome";
  //cout << "Longest palindrome string in the string \"" << str << "\" is \"" << longestPalindrome(str) << "\" " << endl;
  cout << "Longest palindrome string in the string \"" << str << "\" is \"" << longestPalindrome_dp(str) << "\" " << endl;

  return 0;
}
