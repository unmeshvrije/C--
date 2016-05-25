#include<iostream>
#include<map>

using namespace std;

int main(int argc, char *argv[])
{
  std::map<char, int> mymap;
  string str = argv[1]; //"asgsdf";

  for (int i = 0; i < str.size(); ++i) {
    mymap[str[i]]++;
  }

  for (std::map<char,int>::const_iterator it = mymap.begin(); it != mymap.end(); ++it) {
    cout << it->first << ":" << it->second << endl; 
  }
}
