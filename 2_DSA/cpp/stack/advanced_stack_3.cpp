#include <iostream>
#include <stack>

using namespace std;

bool paren_check(const string& s){
    stack<char> stk;
    for(char c:s){
        if(c=='(' || c=='{' || c=='['){
            stk.push(c);
        }else{
            if(stk.empty() ||
                (stk.top() == '(' && c!=')')  ||
                (stk.top() == '{' && c!='}')  ||
                (stk.top() == '[' && c!=']')  )
                return false;
            stk.pop();
        }
    }
//     if(stk.empty()) return true;
//     else return false;
    return stk.empty();
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