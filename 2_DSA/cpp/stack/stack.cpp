#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
    STACK : LIFO(Last-in First-Out)
    
    Use example : 
    [1] text editor undo
    [2] back from web browser
    [3] function recall

    functions:
    push(e) - add element 'e' to the top
    pop()   - delete top element
    top()   - call the top element or use peek()
    empty() - return true if empty stack or false
    size()  - count the element

    By array: allocating array and latest point by 't' value
    - push() : incrase 1 value to 't' value and insert e
    - pop() : decrease 1 value to 't' value
    - top() : return arr[t]
        ex)
        0   1   2   3   ...  
        [10][20][30][40]..., n=10
                        t
    pros) easy struct, fast insert and delete
    cons) more than previous size, occurs the error called 'stack overflow'

    By list: 
    - push(e) : push_first(e)
    - pop()   : pop_first()
    - top()   : return value(head->next)
        ex)
        [head]->[30][-]->[20][-]->[10][-]-END
                top
    pros) no limit to the size
    cons) complicated struct and too much time to insert and delete the element than array

*/

template <typename T>
class Stack{
public:
    Stack() {}

    void push(const T& e){ v.push_back(e); };
    void pop(){ v.pop_back(); };
    const T& top() const{ return v.back(); };

    bool empty() const{return v.empty(); };
    int size() const{ return v.size(); };
private:
    vector<T> v;
};


int main(){
    
    Stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();

    cout<< stk.top() <<endl;
    stk.push(40);

    while(!stk.empty()){
        auto& e = stk.top();
        cout << e << ", ";
        stk.pop();
    }
    cout<<endl;

    return 0;    
}