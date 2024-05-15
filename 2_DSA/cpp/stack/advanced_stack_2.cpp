#include <iostream>
#include <stack>

using namespace std;

/*
    [] : brackets
    {} : braces
    () : parentheses

    Condition : 
    1. must be pair
    2. same pair of brackets must be first open side then close side
    3. must be final section of open bracket and close bracket must be first
    
    ex. 
    "(){}[]"
    "((((((()))))))"
    "(){[()]}"
*/

/*
    algorithm:
    1. open : (,{,[ -> push
    2. close: ),},]
        2.1. stack->empty : "false"
        2.2. Check stack.top() open/close pair 
            -> if correct stack.pop()
            -> if not, return false
    3. check all characters, check stack empty()
        return true is empty() else false    
    */

bool paren_check(const string& s){
    stack<char> stk;
    for(char c:s){
        if(c=='(' || c=='{' || c=='['){
            stk.push(c);
        }else{
            if(stk.empty())
                return false;
            
            if((stk.top()== '('&& c==')')  ||
                (stk.top()== '{'&& c=='}') ||
                (stk.top()== '['&& c==']') )
                stk.pop();
            else{
                return false;
            }   
        }
    }
    if(stk.empty()) return true;
    else return false;
}

int main(){
    // Correct
    cout << paren_check("(){}[]")<<endl;
    cout << paren_check("((((((()))))))")<<endl;
    cout << paren_check("(){[()]}")<<endl;
    
    // False
    cout << paren_check("((({}))")<<endl;
    cout << paren_check(")(")<<endl;
    cout << paren_check("({)}")<<endl;

    return 0;
}