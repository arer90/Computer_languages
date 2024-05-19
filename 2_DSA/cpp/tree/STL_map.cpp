#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
    std::map:
    - key, value
    - sorted by key index
    - insert, delete, travesal = O(logn)
    - std::map = red-black tree
    - if u want to have duplicate values, use std::multimap
    - if u want to unorder sorting array, use std::unordered_map
    - if u want to data type, it need to compare each other
    - <map> is already settled up

    functions:
    begin(), end(),
    rbegin(), rend(),
    insert() // emplace()
    erase()
    operator[] // reference by certain key  // at()
    find()  // contains()
    clear()
    size()
    empty()
*/

int main(){

    map<string, int> fruits;
    fruits.insert({"apple", 1000});
    fruits.insert({"banana", 1500});
    fruits["strawberry"];
    fruits["orange"]=3000;
    fruits["graph"]=4000;
    fruits["lemon"]=5000;


    fruits["apple"]=2000;
    fruits.erase("graph");

    // cout<< fruits["apple"] << endl;

    for(const auto& p: fruits)
        cout<<p.first << " is " << p.second << " won." <<endl;
    
    cout<<endl;

    for(auto [name, price] : fruits)
        cout<< name << " is " << price << " won." <<endl;

    return 0;
}