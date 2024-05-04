#include <iostream>
#include <list>

using namespace std;

/*
    queue: like braid hair
    - FIFO (First-In First-Out)
    - insert : rear side
    - delete : front side

    functions():
    - enquene(e): add rear side to element e. just like push(e) in stack
    - dequeue() : delete front side of element e
    - front()   : return element of front side. ==peek()
    - empty()   : return true if is empty or false
    - size()    : counts of queue

    ex.
    enqueue(e): increase 1 value to rear side and allocate arr[rear]=e
    [array]
    [10][20][30][ ][ ][ ][ ]..., N=10 
        |front  |rear
    
    [Linked_list]
    [null][-][-] <-> [-][10][-] <-> [-][20][-] <-> [-][30][-] <-> [-][-][null]
    header               |header                      |rear          tail
*/

template<typename T>
class Queue{
public:
    Queue() {}
    void enqueue(const T& e){ lst.push_back(e); };
    void dequeue() { lst.pop_front(); }
    const T& front() const { return lst.front(); }
    bool empty() const {return lst.empty(); }
    int size() const{ return lst.size(); };
private:
    std::list<T> lst;
};

int main(){
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();

    cout<< q.front() <<endl << endl;

    q.enqueue(40);

    while(!q.empty()){
        auto& e = q.front();
        cout << e << endl;
        q.dequeue();
    }
    cout<<endl;
    
    return 0;
}