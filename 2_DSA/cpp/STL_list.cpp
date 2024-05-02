#include <iostream>
#include <list>

using namespace std;

/*
    std::list()
    = double linked list container
    = O(1) insert and delete element
    = cannot find certain index
        - it is not working as a operator[] in std::vector
        - begin(), end() iterator can be settup with ++ and --
    = <list>
*fucntions:
[1] front(),back() - list first and last element
[2] begin(), end() - return iterator
    - cbegin(), cend() - constant random access iterator
    - rbegin(), rend() - reverse version
    - crbegin(), crend() -
[3] insert() - add new element
    - push_front() - add a new element to front
    - push_back() - add a new element to end
    - emplace(targe index, target val) - add a new element
[4] clear() - delete all
    - erase() -
    - pop_front() - 
    - pop_back() - 
[5] splice() - move to other list like merging two list
[6] remove(), remove_if - delete certain element or condition
[7] reverse() - reverse the list
[8] unique() - delete duplicating element
[9] sort() - sorting                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
*/

int main(){
    list<int> l1;
    l1.push_back(10);   // 10
    l1.push_back(20);   // 10 -> 20
    
    list<int> l2 {10,20,30,40};

    for(auto a: l2)
        cout<<a<<", ";
    cout<<endl;

    l2.splice(l2.end(), l1);

    for(auto a: l2)
        cout<<a<<", ";
    cout<<endl;

    l2.sort();

    for(auto a: l2)
        cout<<a<<", ";
    cout<<endl;

    l2.unique();;

    for(auto a: l2)
        cout<<a<<", ";
    cout<<endl;

    return 0;
}