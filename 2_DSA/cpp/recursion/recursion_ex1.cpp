#include <iostream>

using namespace std;

long long factorial(int n){           
    if(n==0){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int main(){

    cout<< factorial(3) << endl;
    cout<< factorial(5) << endl;
    cout<< factorial(10) << endl;
    cout<< factorial(20) << endl;
    // int 4 bytes -2,147,483,648 - 2,147,483,647
    // long long 8 bytes -9,223,372,036,854,775,808 - 9,223,372,036,854,775,807
    return 0;
}