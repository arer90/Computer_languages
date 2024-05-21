#include <iostream>
#include <string>
#include <vector>
#include <queue> // priority queue

using namespace std;

/*
    *priority_queue: value with priority setting without insert condition
    - FIFO
    - ex. Emergency, network traffic, OS
    
    *function(time complexity):
                                  insert   |  remove
    array without sorted       |  O(1)     | O(n)
    linked list without sorted |  O(1)     | O(n)
    sorted array               |  O(n)     | O(1)
    sorted linked list         |  O(n)     | O(1)
    heap                       |  O(logN)  | O(logN)

    *C++ STL
    - std::priority_queue
    - composed with 'container'
    - only priority values without inserting series
    - <queue> setting
    
    *functions:
    push(e) : add element e    : O(logN)
    pop()   : remove element e : O(logN)
    top()   : call top element : O(1)
*/

class Student{
public:
    string name;
    int score;

    bool operator < (const Student& st) const{
        return score < st.score;
    }
};

template<typename T>
void print_queue(T q){
    while(!q.empty()){
        cout<< q.top() << ", ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    
    vector<int> vec {4,2,3,5,1};
    priority_queue<int> pq1;
    for(auto n: vec)
        pq1.push(n);
    print_queue(pq1);

    priority_queue<int, vector<int>, greater<int>> pq2(vec.begin(), vec.end());
    print_queue(pq2);

    priority_queue<Student> students;
    students.push({"Amelia", 80});
    students.push({"Soplia", 40});
    students.push({"Olivia", 95});
    students.push({"George", 80});
    
    while(!students.empty()){
        auto& s = students.top();
        cout << s.name << " (" << s.score << ")" <<endl;
        students.pop();
    }
    cout<<endl;

    return 0;
}