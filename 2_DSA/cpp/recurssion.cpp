#include <iostream>
#include <chrono>
using namespace std;

/*
    recursion : 
    pros] code can be simple
    cons] hard debugging, stack overflow, low efficient
*/

int sum_ori(int n){ // O(n)
    int s=0;
    for(int i=1;i<=n;++i){
        s+=i;
    }
    return s;
}

int sum(int n){     // O(n) + function overhead
    if(n==1)
        return 1;
    else
        return n + sum(n-1);    
}

int main(){

    auto start2 = chrono::system_clock::now();
    volatile int s = 0;
    for(int n=1;n<=20000;++n)
        s = sum_ori(n);

    // cout<< sum_ori(10)<<endl;
    // cout<< sum(10)<<endl;

    auto end2 = chrono::system_clock::now();
    auto msec2 = chrono::duration<double>(end2-start2).count()*1000;
    cout << "iterative sum_iterative: "<< msec2 << " ms"<< endl;

    auto start1 = chrono::system_clock::now();
    s = 0;
    for(int n=1;n<=20000;++n)
        s = sum(n);

    // cout<< sum_ori(10)<<endl;
    // cout<< sum(10)<<endl;

    auto end1 = chrono::system_clock::now();
    auto msec1 = chrono::duration<double>(end1-start1).count()*1000;
    cout << "recursive sum_iterative: "<< msec1 << " ms"<< endl;   // <-- over head problem

    //cml : g++ -O2 -o recursion.exe recursion.cpp

    return 0;
}