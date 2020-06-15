#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    std::vector<double> test = {1.3, 4.6, 89.234, -3.45435, 0.0988};
    std::string doubleStr;
    std::transform(std::begin(test),
               std::end(test), 
               std::back_inserter(doubleStr),
               [](double d) { return std::to_string(d); } 
              );
    std::cout << doubleStr << std::endl;
    return 0;
}

