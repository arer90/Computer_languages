#include <iostream>

using namespace std;

/*
Double_Linked_List 
[Pros]  1. search from head or tail
[Cons]  1. necessary extra space 
        2. data insert and remove coding is complicated

*/

struct Node{
    int data;
    Node* prev;
    Node* next;
};

class doublell{
private:
    int count;
    Node* head;
    Node* tail;
public:
    doublell(){
        count=0;
        head = new Node {0, nullptr,nullptr};
        tail = new Node {0, nullptr,nullptr};
        head->next = tail;
        tail->prev = head;
    };
    ~doublell(){
        while(!empty()){
            pop_front();
        }
        delete head;
        delete tail;
    }

    //////////////    
    bool empty(){
        return count==0;
    }
    int size(){
        return count;
    }
    //////////////    

    //////////////    
    void insert(Node* p, int val){
        Node* new_node = new Node {val, p->prev, p};
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void push_front(int val){
        insert(head->next, val);
    }
    void push_back(int val){
        insert(tail, val);
    }
    //////////////
    
    //////////////
    void erase(Node* p){
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }
    void pop_front(){
        if(!empty()){
            erase(head->next);
        }
    }
    void pop_back(){
        if(!empty()){
            erase(tail->prev);
        }
    }
    //////////////

    //////////////
    void print_all(){
        Node* curr = head->next;
        while(curr!=tail){
            cout<<curr->data<<", ";
            curr = curr->next;
        }
        cout<< endl;
    }

    void print_reverse(){
        Node* curr= tail->prev;
        while(curr!=head){
            cout<<curr->data<<", ";
            curr = curr->prev;
        }
        cout<<endl;
    }
    //////////////

};

int main(){
    doublell ll;
    ll.push_back(10);    
    ll.push_back(20);    
    ll.push_back(30);    
    ll.print_all();
    ll.print_reverse();

    ll.pop_front();
    ll.pop_back();
    ll.print_all();

    ll.push_back(100);
    ll.push_back(400);
    ll.print_all();

    return 0;
}