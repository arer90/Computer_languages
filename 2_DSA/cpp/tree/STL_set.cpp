#include <iostream>
#include <set>
#include <string>

using namespace std;

/*
    set : only save key
    map : save key and value

    set vs multiset:
    - set is no duplicate
    - multiset is allowed to have a duplicated value

    set vs unordered_set:
    - set is inner data with sorted 
    - unordered_set is no sorted

    std::set:
    - key = value
    - saved date is settled with key value
    - insert, delete, travesal = O(logn)
    - std::set = red-black tree
    - if u want to have duplicate values, use std::multiset
    - if u want to unorder sorting array, use std::unordered_set
    - if u want to data type, it need to compare each other
    - <set> is already settled up

    functions:
    begin(), end(),
    rbegin(), rend(),
    insert() // emplace()
    erase()
    find()  // contains()
    clear()
    size()
    empty()
*/

int main(){

    set<int> odds;
    odds.insert(1);
    odds.insert(7);
    odds.insert(5);
    odds.insert(3);
    odds.insert(9);

    // set<int> odds {1,3,5,7,9};
    set<int, greater<>> evens {2,4,6,8};

    evens.insert(10);
    evens.insert(2);

    if(evens.find(4)!=evens.end())
        cout<<"4 is found!"<<endl;
    else
        cout<<"4 is not found!"<<endl;

    for(auto n: odds)
        cout<<n<<", ";
    cout<<endl;

    for(auto n: evens)
        cout<<n<<", ";
    cout<<endl;


    using psi = pair<string, int>;
    // error occured by no comparing functions 
    // struct psi{
    //     string first;
    //     int second;
    // };

    // set<pair<string, int>> = set<psi>
    set<psi> managers{{"Amelia",29},    
                                    {"Noah",25},
                                    {"Olivia",31},
                                    {"Sophia",40},
    };
    managers.insert(make_pair("George",35));
    psi person1 = {"Noah", 25};
    if(managers.find(person1)!=managers.end())
        cout<<person1.first << " is a managers" << endl;
    else
        cout<<person1.first << " is not a managers" << endl;

    managers.erase({"Sophia",40});
    managers.erase({"Noah",30});

    for(const auto& m : managers)
        cout<< m.first << "(" << m.second << ")" << endl;


    return 0;
}