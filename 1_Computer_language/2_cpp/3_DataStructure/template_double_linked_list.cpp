#include <iostream>

using namespace std;

/*
    1. using iterator
    2. data serach
    3. 

*/
template <typename T>
struct Node{
    int data;
    Node* prev;
    Node* next;
};

template <typename T>
class doublell{
private:
    T count;
    Node<T>* head;
    Node<T>* tail;
public:
    class iterator{
    private:
        Node<T>* ptr;
    public:
        iterator() : ptr(NULL) {}
        iterator(Node<T> *p) : ptr(p) {}
        
        T& operator*() {  return ptr->data; }

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
        head = new Node<T> {T(), nullptr,nullptr};
        tail = new Node<T> {T(), nullptr,nullptr};
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
    void insert(const iterator& pos, const T& val)
    {
        Node<T>* p = pos.ptr;    
        Node<T>* new_node = new Node<T> {val, p->prev, p};
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void push_front(const T& val){
        insert(begin(), val);
    }
    void push_back(const T& val){
        insert(end(), val);
    }
    //////////////
    
    //////////////
    void erase(const iterator& pos){
        Node<T>* p = pos.ptr;
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

    iterator find(const T& val){
        Node<T>* curr = head->next;
        while(curr->data !=val && curr != tail){
            curr = curr->next;
        }
        return iterator(curr);
    }
};

int main(){


    doublell<int> ll;
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