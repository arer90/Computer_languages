#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    heap: accumulate the data
    - completed binary tree. so usually called as 'binary heap'.
    - heap poroperty
        [1] max heap property : parent key node always equal or greater than child node
        [2] min heap property : parent key node always equal or lower than child node
    *Properties
    1. root node = max or min value
    2. only comparing with value difference between parent - child node.
        (no relation between left and right)
    3. completed binary tree: h=[log_2(n)]
    4. advnaced uses: heap sort, priority queue, Dijkstra's algorithm

    *Time Complexity
    - min or max reference: O(1)
    - value insert: O(n)
    - value remove: O(n)

                                             heap vs BST
                 tree style| Completed Binary tree | Binary tree
                  duplicate|  O                    | X
               element sort|  no sorted            | sorted
        fast element search|  unsupported(O(n))    | supported (O(logN))
   element insert or remove|  O(logN)              | O(logN)/O(n)
                max/min ref|  O(1)                 | O(logN)/O(n)

    *Implementation
    - Completed Binary tree, Node=> INDEx, can use [array]
    - Start root node -> index 1 (ignoring 0)
    - L=0,1,2,3
    - index m 
        -> parent's index = m/2;
        -> left child's index = m*2;
        -> right child's index= m*2=1;

*/

class MaxHeap{
private:
    vector<int> vec;
public:
    MaxHeap() : vec(1) {}
    void push(int value){
        vec.push_back(value);
        heapify_up(vec.size()-1);
    }
    void pop(){
        vec[1] = vec.back();
        vec.pop_back();
        heapify_down(1);
    }
    int top() const { return vec[1]; }
    int size(){ return vec.size()-1; }
    bool empty(){ return vec.size()==1;}
    void print(){
        for(auto n: vec){
            cout<< n << ", ";
        }
        cout<<endl;
    }

private:
    int parent(int i){  return i/2;}
    int left(int i){  return 2*i;}
    int right(int i){  return 2*i+1;}
    void heapify_up(int i){
        if(i>1 && vec[i] > vec[parent(i)]){
            swap(vec[i], vec[parent(i)]);
            heapify_up(parent(i));
        }
    }
    void heapify_down(int i){
        int largest = i;
        if(left(i) < vec.size() && vec[left(i)] > vec[largest])
            largest = left(i);
        if(right(i) < vec.size() && vec[left(i)] > vec[largest])
            largest = right(i);
        if(largest!=i){
            swap(vec[i], vec[largest]);
            heapify_down(largest);
        }
    }
};

int main(){
    MaxHeap heap;
    heap.push(10);
    heap.push(5);
    heap.push(15);
    heap.push(7);
    heap.push(3);
    heap.push(9);
    heap.push(14);
    heap.push(8);
    heap.push(2);
    heap.push(4);
    // heap.print();
    // 0, 15, 8, 14, 7, 4, 9, 10, 5, 2, 3, // 0 is index

    while(!heap.empty()){
        cout<< heap.top() << ", ";
        heap.pop();
    }
    cout<<endl;

    return 0;
}