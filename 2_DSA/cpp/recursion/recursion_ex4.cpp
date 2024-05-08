#include <iostream>
#include <numeric>

using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int lcm(int a, int b){
    return a*b / gcd(a,b);  
}

int main(){

    cout<<"gcd1: "<< gcd(10,15) <<endl; // "gcd2: "<< std::gcd(10,15)<<endl;
    cout<<"lcm1: "<< lcm(10,15) <<endl; // "lcm2: "<< std::lcm(10,15)<<endl;
    
        
    return 0;
}