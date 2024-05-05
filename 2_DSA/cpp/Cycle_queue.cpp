#include <iostream>
#include <queue>

using namespace std;

/*
Queue
    array] problem -> contiuous inserting and deleting elements 
                        can cause the increasing size of useless space

Circular queue : FIFO, but last queue directly connects to first queue
- Queue front and rear will clockwise move -> array with '%'
- Queue empty and full will be checked by count

*/

#define MAX_QUEUE 10

template <typename T>
class CircularQueue{
public:
CircularQueue(int sz = MAX_QUEUE){
    arr=new T[sz];
    front_idx = 0;
    rear_idx =0;
    count =0;
    capacity=sz;
}

~CircularQueue(){
    delete [] arr;
}
void enqueue(const T& e){
    if(full()){
        std::cout<<"Overflow error!"<<std::endl;
        return;
    }
    rear_idx = (rear_idx + 1) % capacity;
    arr[rear_idx] = e;
    count++;
}
void dequeue(){
    if(empty()){
        std::cout<<"underflow error!"<<std::endl;
        return;
    }
    front_idx = (front_idx + 1) % capacity;
    count--;
}
const T& front() const { return arr[front_idx];}
bool empty() const {return count==0;}
int full() const {return count==capacity;}
int size() const {return count;}

private:
T* arr;
int front_idx;
int rear_idx;
int count;
int capacity;
};

int main(){
    CircularQueue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    while(!q.empty()){
        auto& e=q.front();
        cout<<e<<", ";
        q.dequeue();
    }
    cout<<endl;

    return 0;
}