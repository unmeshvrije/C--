#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream file(argv[1]); // pass file name as argment
    string linebuffer;

    while (file && getline(file, linebuffer)){
        if (linebuffer.length() == 0)continue;

        // do something

    }
    return 0;
}
