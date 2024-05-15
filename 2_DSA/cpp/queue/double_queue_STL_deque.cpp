#include <iostream>
#include <deque>

using namespace std;

/*
    deque : double ended Queue
    - available to insert and delete both sides.

    ---------------------
    [10][20][30][40][50]
    ---------------------
    |front          |back

    functions:
    push_front(e) : insert element e to front side
    pop_front()   : delete element e from front side
    push_back(e)  : insert element e to back side
    pop_back()    : delete element e from back side
    front()       : call front element
    back()        : call back element
    empty()       : return true if no queue
    size()        : return count of queue

    [construct]
    1. array : circular queue with 'front' and 'rear' index
    2. linked_list : double linked list with head & tail
    
    std::deque
    [1] search element with O(1) 
    [2] insert and delete front and rear with O(1)
    [3] if middle of queue, insert and delete with with O(n)
    [4] std::stack, std::queue is basic
    [5] std::deque is not using the chunk 
            but using various size of memory chunk
*/

int main(){

    deque<int> d {10,20,30,40};

    d.push_front(50);
    d.push_back(60);

    for(int i=0;i<d.size(); ++i){
        std::cout << d[i] << ", ";
    }
    std::cout<<endl;

    for(auto i: d){
        std::cout << i << ", ";
    }
    std::cout<<endl;

    return 0;
}