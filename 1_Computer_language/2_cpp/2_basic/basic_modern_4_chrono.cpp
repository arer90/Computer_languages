#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>

using namespace std;

/*

'chrono' library : can estimate the code calculation with nano second
release mode is much better
cml:# g++ -O2 -o *.exe *.cpp
*/

vector<int> odds() {
    return {1, 3, 5, 7, 9};
};


int main(){
    auto start = chrono::system_clock::now();   // time point

    // Do something
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


    //

    auto end = chrono::system_clock::now();
    auto msec= chrono::duration<double>(end-start).count()*1000;
    cout << "Elasped time: " << msec << "ms." << endl;

    return 0;
}
