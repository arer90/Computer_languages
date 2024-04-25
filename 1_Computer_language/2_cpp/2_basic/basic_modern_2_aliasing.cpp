#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// C language and c++03
typedef unsigned char uchar;
typedef pair<int, string> pis;
typedef double da10[10];
typedef void (*func)(int);

// after C++ 11 
using uchar = unsigned char;
using pis   = pair<int, string>;
using da10  = double[10];
using func  = void(*)(int);

template <typename T>
using matrix1d = vector<T>;

void my_function(int n){
    //
}

int main(){
    da10 arr {};
    matrix1d<float> vec(3);
    func fp = &my_function;

    return 0;
}