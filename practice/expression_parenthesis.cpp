#include<iostream>
#include<vector>
#include<cctype>

using namespace std;


//  01234567
/*  123+455*78*/

vector<string> parenthesize(string expr) {

  int size = expr.size();
  vector<string> result;
  for (int i = 0; i < size; ++i) {
    if (ispunct(expr[i])) {
      vector<string> left = parenthesize(expr.substr(0, i));
      vector<string> right = parenthesize(expr.substr(i+1));
      for (int j = 0; j < left.size(); ++j) {
        for (int k = 0; k < right.size(); ++k) {
          cout << "(" << left[j] << " " << expr[i] << "(" << right[k]  << ")"  << ")" << endl;
          result.push_back (left[j] + expr[i] + right[k]);
        }
      }
    }
  }

  if (result.size() <= 0) {
    result.push_back(expr);
  }

  return result;
}

int main(int argc, char* argv[]) {

  vector<string> result;
  string input = argv[1];
  parenthesize(input);

  for (int i = 0; i < result.size(); ++i) {
    //cout << result[i] << endl;
  }
  return 0;
}
