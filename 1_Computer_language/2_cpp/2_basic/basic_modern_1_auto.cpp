#include <iostream>
#include <vector>
#include <string> // Include for std::string
#include <cmath>

using namespace std;

vector<int> odds() {
    return {1, 3, 5, 7, 9};
};

int main() {
    auto a1 = 10;            // int
    auto a2 = 3.14f;         // float
    auto a3 = "hello";       // const char*
    auto a4 = string("hello"); // std::string, better than "hello"s
    auto a5 = sqrt(2.0);     // double
    auto a6 = odds();        // vector<int>
    auto a7 = a6.begin();    // vector<int>::iterator

    // Unused lambda function
    auto lambda = [](int x) { return x * 2; };

    return 0;
}
