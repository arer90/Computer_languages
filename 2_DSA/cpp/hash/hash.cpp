#include <iostream>
#include <vector>

using namespace std;

/*
    hash: decomposition, randomly sorted
    hashing: allocating the index number with values,
            and using for calling certain data
    example: fastest search method, MDS, SHA, BST=O(logN)

    implmentation:
    require: allocating bool type with saving int data container
        bool data[8] ={};
        data[2] = true;
        data[4] = true;
        data[5] = true;
        data[7] = true;
    
    *question: too many numbers, data is real number or not number?
    - using mapping
    - hash(x) = x%n
    -   bool data[7] ={};
        data[2 % 7] = true;
        data[4 % 7] = true;
        data[5 % 7] = true;
        data[9999 % 7] = true;
*/

class hash_set{
private:
    int sz;
    std::vector<int> data;
public:
    hash_set(int n) : sz(n), data(sz, -1) {}
    int hash(int key){  return key % sz; }
    void insert(int value){ data[hash(value)]=value;}
    bool find(int value){   return (data[hash(value)]==value);}
    void erase(int value){  data[hash(value)]= -1;}
    void print(){
        for(auto n: data){
            cout << n << ", ";
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
    num_set.print();

    int value = 10;
    if(num_set.find(value))
        cout<< value << " is found!" << endl;
    else
        cout<< value << " is not found!" << endl;
    
    num_set.insert(2);
    num_set.print();

    value = 100;
    if(num_set.find(value))
        cout<< value << " is found!" << endl;
    else
        cout<< value << " is not found!" << endl;

    return 0;
}