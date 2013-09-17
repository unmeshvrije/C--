#include<iostream>

using namespace std;

main(int argc ,char *argv[])
{
   int i;
   cout << "No .of args = argc = "<<argc;
   
   for(i=0; i < argc  ; i++)
   cout << endl << argv[i];
}
