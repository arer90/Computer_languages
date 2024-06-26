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

    vector<int> numbers {10,20,30};
    // for(auto iter = begin(numbers); iter<end(numbers);iter++){
    //     cout << *iter << endl;
    // }
    for(int n: numbers){
        cout << n << endl;
    }

    for(auto& n: numbers){
        cout << n << endl;
    }

    string strs[] = {"My","code","is","best"};
    for(const auto& s: strs){   // const : no object copy, '&' : no change order
        cout << s << " ";
    }
    cout<<endl;

    return 0;
}
