#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

#include <stack>
void separateQuery(string logLine, vector<string>& tokens) {
    stack<int> spaceIndexes;
    size_t index = string::npos;
    int cntIndexes = 0;
    
    while (cntIndexes < 4) {
        index = logLine.find_last_of(" ", index);
        cout << "space found at index = " << index << endl;
        assert(index != string::npos);
        index--;
        spaceIndexes.push(index);
        cntIndexes++;
    }

    int startIndex = 0;
    while(!spaceIndexes.empty()) {
        int index = spaceIndexes.top();
        spaceIndexes.pop();
        //int nextIndex = spaceIndexes.top();
        tokens.push_back(logLine.substr(startIndex, (index - startIndex)+1));
        startIndex = index+2;
    }
    tokens.push_back(logLine.substr(startIndex, (index - startIndex)+1));

    int i = 1;
    for (auto t: tokens) {
        cout << i++ << ")" << t << endl;
    }
}

int main(int argc, char *argv[]) {

    vector<string> tokens;
    string s1("RP1052(A,\"(A)National Security (B) Public Accounts(C)Rules,Business,Procedures & Privliges (D) Foreign Affairs (E) Kashmir\"@en) 127573784412525.000000,25022094,94105,98,15456,4 12.261000 48.009000 1");
    string s2("RP1158(A,\"NJT Bus: 26, 52, 56, 57, 58, 59, 62, and 112\"@en) 128518422280101.000000,25069479,94105,98,15456,4 10.698000 49.229000 1");
    string s3("RP1589(A,\"J. Mex. Chem. Soc.\"@en) 129235245805325.000000,25105419,94105,98,15456,4 12.321000 46.284000 1");

    separateQuery(s1, tokens);
    //RP1355(<http://dbpedia.org/resource/Rhodes_College>,"Truth, Loyalty, Service"@en) 66681661790309.000000,3,94105,98,15456,4 13.835000 78.571000 1
    //RP461(A,"Sun Devils"@en) 128423970266399.000000,25064740,94105,98,15456,4 12.444000 52.734000 1
    //RP1397(A,"The Hamptons"@en) 127622812670741.000000,25024554,94105,98,15456,4 11.898000 49.540000 1
    //RP1412(A,"44.1 WOUC-HD"@en) 128093435494409.000000,25048164,94105,98,15456,4 13.327000 46.480000 1
    //RP587(<http://dbpedia.org/resource/AMSAT__2>,"Barry Baines WD4ASW"@en) 63221901993125.000000,3,94105,98,15456,4 13.915000 74.231000 1
    //RP474(<http://dbpedia.org/resource/60th_Delaware_General_Assembly>,"60th General Assembly"@en) 69330535501949.000000,3,94105,98,15456,4 17.446000 73.942000 1
    //RP1320(A,"Almost Grown"@en) 132466144874849.000000,25267224,94105,98,15456,4 11.916000 44.728000 1
    return 0;
}
