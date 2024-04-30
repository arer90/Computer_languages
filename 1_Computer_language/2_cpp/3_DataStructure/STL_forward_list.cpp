#include <iostream>
#include <forward_list>

using namespace std;

/*
    std::forward_ list()
    = single linked list container
    = begin() with ++ usable
    = c++ 11 and more
    = <forward_1list>

*fucntions:
[1] front(),back() - list first and last element
[2] begin(), end() - return iterator
[3] insert_after() - add new element
    - emplace(targe index, target val) - add a new element
[4] clear() - delete all
    - pop_front() - 
    - pop_back() -  
[5] [X] size
*/

int main(){
    forward_list<int> l1 {10,20,30,40};
    l1.push_front(40);  // 40,10,20,30,40
    l1.push_front(30);  // 30,40,10,20,30,40

    for(auto a: l1)
        cout<< a<<",";
    cout<<endl;

    int cnt = distance(l1.begin(), l1.end());
    cout << cnt << endl;
    
    l1.remove(40);  // 30,[40],10,20,30,[40]
    
    for(auto a: l1)
        cout<< a<<",";
    cout<<endl;

    l1.remove_if([](int n){return n>20;});  // 
    
    for(auto a: l1)
        cout<< a<<",";
    cout<<endl;




    return 0;
}