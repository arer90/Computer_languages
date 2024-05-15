#include <iostream>

using namespace std;

/*
    1. using iterator
    2. data serach
    3. 

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
    class iterator{
    private:
        Node* ptr;
    public:
        iterator() : ptr(NULL) {}
        iterator(Node *p) : ptr(p) {}
        
        int& operator*() {  return ptr->data; }

        iterator& operator++(){     // ++it
            ptr = ptr->next;
            return *this;   // *this -> self as reference
        }
        iterator& operator--(){     // ++it
            ptr = ptr->prev;
            return *this;   // *this -> self as reference
        }

        bool operator==(const iterator& it) const{
            return ptr == it.ptr;
        }

        bool operator!=(const iterator& it) const{
            return ptr != it.ptr;
        }

        friend class doublell;
    };

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

    iterator begin() const{
        return iterator(head->next);
    }

    iterator end() const{
        return iterator(tail);
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
    void insert(const iterator& pos, const int val)
    {
        Node* p = pos.ptr;    
        Node* new_node = new Node {val, p->prev, p};
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void push_front(const int  val){
        insert(begin(), val);
    }
    void push_back(const int val){
        insert(end(), val);
    }
    //////////////
    
    //////////////
    void erase(const iterator& pos){
        Node* p = pos.ptr;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }
    void pop_front(){
        if(!empty()){
            erase(begin());
        }
    }
    void pop_back(){
        if(!empty()){
            erase(--end());
        }
    }
    //////////////

    iterator find(const int n){
        Node* curr = head->next;
        while(curr->data !=n && curr != tail){
            curr = curr->next;
        }
        return iterator(curr);
    }

    // //////////////
    // void print_all(){
    //     Node* curr = head->next;
    //     while(curr!=tail){
    //         cout<<curr->data<<", ";
    //         curr = curr->next;
    //     }
    //     cout<< endl;
    // }

    // void print_reverse(){
    //     Node* curr= tail->prev;
    //     while(curr!=head){
    //         cout<<curr->data<<", ";
    //         curr = curr->prev;
    //     }
    //     cout<<endl;
    // }
    // //////////////

};

int main(){


    doublell ll;
    ll.push_back(10);    
    ll.push_back(20);    
    ll.push_back(30);    

    auto it = ll.find(20);
    if(it!=ll.end()){
        ll.insert(it, 50);
    }

    for(auto n:ll){
        cout << n << ", ";
    }
    cout<<endl;

    return 0;
}