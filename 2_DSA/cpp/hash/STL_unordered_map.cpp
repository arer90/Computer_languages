#include <iostream>
#include <map>
#include <unordered_map>

#include <string>
#include <vector>

using namespace std;

/*
    std::unordered_map: pair(key value, Type T valuae)
        - data insert, delete, serach = TC O(1)
        - no duplicated value! if u want to multiple same numbers, std::unordered_multimap
        - if u want to compare with other by hash function, set up the keyequal
        - similiar to the std::map
*/


int main(){
    // map<string, int> fruits;
    unordered_map<string, int> fruits;
    // map vs unordered_map : map with sorted in key value, unorered_map is not sorted
    fruits.insert({"apple", 1000});
    fruits.insert({"banana", 1500});
    fruits["orange"]=3000;
    fruits["graph"]=4000;
    fruits["lemon"]=5000;

    fruits["apple"]=2000;
    fruits.erase("graph");

    for(auto [name, price]: fruits)
        cout<< name << " is " << price <<" won!" << endl;
    
    return 0;
}
