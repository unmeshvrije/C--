#include<iostream>
#include<stack>
#include<string>

using namespace std;

/**
 * 1. Remove all leading and trailing spaces
 * 2. Remove all redundant spaces
 * 3. Reverse the entire string
 * 4. Reverse each individual word
 *
 * Example:
 * "the sky is blue"
 *
 * "eulb si yks eht" (after step 3)
 *
 * "blue is sky the" (after step 4)
 * */

void reverseSubstring(string &s, int start, int end) {
  int i = start;
  int j = end;
  while (i < j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;
  }
}

void reverseWordsInPlace(string &s) {

  // 1. Remove leading and trailing spaces
  s.erase(0, s.find_first_not_of(' '));
  s.erase(s.find_last_not_of(' ')+1);

  cout << "After trim:[" << s << "]" << endl;

  // 2. Remove redundant spaces
  for (int i = 0; i < s.size(); ++i) {
    cout << "i = " << i << endl;
    if (s[i] == ' ') {
      int spaces = 0;
      int j = i+1;
      while (j < s.size() && s[j] == ' ') {
        cout << "Now :[" << s << "]" << endl;
        s.erase(s.begin()+j);
        j = i+1;
      }
    }
  }

  //3. Reverse entire string
  reverseSubstring(s, 0, s.size()-1);

  //4. Reverse each word
  int begin = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ') {
      reverseSubstring(s, begin, i-1);
      begin = i+1;
    }
  }
  reverseSubstring(s, begin, s.size()-1);
}

void reverseWords(string &s) {
        stack<char> words;
        stack<char> reverse;

        cout << "before trim: [" << s <<"]" << endl;
        s.erase(0, s.find_first_not_of(' '));  //prefixing spaces
        s.erase(s.find_last_not_of(' ')+1);     // Suffixing spaces
        cout << "after trim: [" << s <<"]" << endl;

        for (int i = 0; i < s.size(); ++i) {
            words.push(s[i]);
        }

        string result = "";
        int index = 0;

        while(!words.empty()) {
            char ch = words.top();
            words.pop();
            if (ch == ' ') {
                while(words.top() == ' ') {
                    words.pop();
                }
                if (!reverse.empty()){
                    while (!reverse.empty()) {
                        result += reverse.top();
                        reverse.pop();
                    }

                    // If it is not the last word, then add space
                    if (!words.empty()) {
                        result += ' ';
                    }
                }
            } else {
                cout << "pusing " << ch << endl;
                reverse.push(ch);
            }
        }

        while(!reverse.empty()) {
          result += reverse.top();
          reverse.pop();
        }
        s = result;
}

int main(int argc, char *argv[]) {
    string str(argv[1]);
    //str.erase(str.begin()+4);
    reverseWordsInPlace(str);
    cout << "after reverse:[" << str <<"]" << endl; 
}
