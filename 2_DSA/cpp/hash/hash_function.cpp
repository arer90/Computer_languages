#include <iostream>
#include <vector>
#include <list>

#include <string>
#include <algorithm>

using namespace std;

/*
    hash function: h(k) = k%n -> h(k)==f(k) % n
    - key: hash input numbers for insert data itself or data
    - hash value: output for hash function
    - hash table: (key, map)
    - bucket(=slot,cell): saving space from hash table
    - collision: coollasping by same hash values
        -> solution: chaining, open addressing, cuckoo hashing
    - Chanining : using linked-list as (separate chaining)
        = hash(x) = x%7         // hash_set num_set(7);
        = num_set.insert(10);   // hash_table idx: 3
        = num_set.insert(15);   // hash_table idx: 1
        = num_set.insert(20);   // hash_table idx: 6
        = num_set.insert(100);  // hash_table idx: 2
        = num_set.insert(2);    // hash_table idx: 2 // if single LinkedList-> 2-> 100

        *Properties
        (1) TC (Time Complexity) insert:  O(1), Worst TC: O(n)
        (2) TC (Time Complexity) remove:  O(n)
        
        *alternative to solve O(n) TC: load factor
        = saving mean count and storing numbers in hash table
                n
            a = -   (n: hash table storing number, m = hashing table size (linked list count))
                m
        = if load factor < 1 = memory waste
        = if load factor > 1 = slow action in search, remove -> need to rehashing for load factor closed to the 1
    
    - Open addressing: if hash collision occured, put the value to different slot i nhash table
                        by linear probing, quardratic probling or double hashing
        *linear probing: if h(key), h(key)+1, h(key)+2....
            ex.) hash(x) = x&7 -> insert(10,15,20,100) as saved 1,2,3,6 -> insert(1)-> #4 saved.
            [cons]: if cluster occured, a performance of this is bad
        *quardratic probling: if h(key), h(key)+1^2, h(key)+2^2....
*/

class hash_set{
private:
    int sz;
    std::vector<std::list<int>> data;
    /*
    <key,value>
    vector<list<pair<string, int>>> data;
    */
public:
    hash_set(int n) : sz(n), data(sz) {}
    int hash(int key){  return key%sz;  }
    void insert(int value){
        data[hash(value)].push_back(value);
    }
    bool find(int value){
        auto& entries = data[hash(value)];
        return std::find(entries.begin(), entries.end(), value)!=entries.end();
    }
    void erase(int value){
        auto& entries = data[hash(value)];
        auto it = std::find(entries.begin(), entries.end(), value);
        if(it!=entries.end())
            entries.erase(it);
    }
    void print(){
        for(int i=0;i<sz;i++){
            cout<<i<<": ";
            for(auto n : data[i]){
                cout<< n <<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    
    hash_set num_set(7);

    
    num_set.insert(10); // 3 idx
    num_set.insert(15); // 1 idx
    num_set.insert(20); // 6 idx
    num_set.insert(100); // 2 idx

    int value = 10;
    if(num_set.find(value))
        cout<< value << " is found!" << endl;
    else
        cout<< value << " is not found!" << endl;
    
    num_set.insert(2);

    value = 100;
    if(num_set.find(value))
        cout<< value << " is found!" << endl;
    else
        cout<< value << " is not found!" << endl;

    num_set.print();

    return 0;
}