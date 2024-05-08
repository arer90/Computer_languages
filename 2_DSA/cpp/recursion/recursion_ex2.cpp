#include <iostream>

using namespace std;

long long fibonacchi(int n){
    if(n<=1){
        return 1;
    }else{
        return fibonacchi(n-2)+fibonacchi(n-1);
    }
}

int main(){
    for(int i=0;i<10;i++){
        cout<< fibonacchi(i) << ", ";
    }
    cout << endl;

    cout<< fibonacchi(40) << endl;
    cout<< fibonacchi(50) << endl;  
    // <- 'overlapping subproblem' = low efficient calculation 


    return 0;
}