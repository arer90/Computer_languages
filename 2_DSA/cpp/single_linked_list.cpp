#include <iostream>

using namespace std;

/*
list :
    - insert
    - remove
    - search
*               | array  |vs.| list
store           | series |   | dynamic space
insert & remove | ineffi.|   | efficient
coding          | easy   |   | complicated

Linked_List:
[Pros]  1. dynamic insert and remove O(1)
        2. no limit with size
[Cons]  1. find certain index : O(N)
        2. necessary extra memory to LINK
        3. complicated with coding
*/

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}    // head== Null, NULL->nullptr
    ~LinkedList(){
        while(!empty()){
            pop_front();
        }
    }

    void push_front(int val){
        Node* new_node = new Node {val, nullptr};
        if(head!=nullptr){
            new_node->next = head;   
        }
        head = new_node;
    }

    void pop_front(){
        if(head==nullptr){
            return;
        }
        Node *first = head;
        head = head->next;
        delete first;
    }

    void print_all(){
        Node* curr =head;
        while(curr!=nullptr){
            cout<<curr->data<<", ";
            curr = curr->next;
        }
        cout<< endl;
    }

    bool empty(){
        return head==nullptr;
    }
};

int main(){
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(40);
    ll.print_all();

    return 0;
}