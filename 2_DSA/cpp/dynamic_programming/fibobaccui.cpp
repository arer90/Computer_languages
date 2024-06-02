#include <iostream>
#include <vector>

using namespace std;

/*
    Dynamic_programming: problem -> subproblem
    - divide and conquer
    - optimizaton problem and counting
        
    ex) [1] 0-1 knapsack problem
        [2] subset sum problem
        [3] LCS : Longest common subsequence
        [4] chain matrix multiplication
        [5] minimum cost path
    
    *before solving DYNAMIC PROBLEM:
    1. overlapping subproblems - decomposing the problem into subproblems
    2. optimal substructure - optimal solution from problem
    
    *Coding
    1. setting: base case
    2. 'process' with state transition
    3. memorization or tabulation to 'process'
*/

/*
    Fibonacci sequence
    - f(0)=0    <- base
    - f(1)=1    <- base
    - f(n)= f(n-2) + f(n-1) (n>1)
    eg. 0,1,1,2,3,5,8,13,21,34,55
        *5 = 2+3
        *21= 13+8
*/

int fibo1(int n){
    // problem occured: duplicating section
    if(n<=1)
        return n;
    return fibo1(n-1) + fibo1(n-2);
}

/*
    *memorization: 
    - top-down process, 
    - saving the duplicated calculation to cache! NOT "Memorization"
    - removing duplicating calculation by recursion -> overhead
    - partial calculation

    *tabulation
    - bottom-up process
    - saving all sub result to the table
    - array type
    - calculating all (start-end) 
*/

// memorization
vector<int> memo(50, -1);
int fibo2(int n){
    if(n<2)
        return n;

    if(memo[n]!=-1)
        return memo[n];
    
    memo[n] = fibo2(n-2) + fibo2(n-1);
    return memo[n];
}

// tabulation
int fibo3(int n){

    vector<int> dp(n+1, 0);
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    return dp[n];
}

int main(){
    int n = 10;
    cout<< fibo1(n) << endl;    // duplicating
    cout<< fibo2(n) << endl;    // memorization
    cout<< fibo3(n) << endl;    // tabulation
    
    return 0;
}