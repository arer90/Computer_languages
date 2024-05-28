#include <iostream>
#include <unordered_set>

#include <string>
#include <vector>

using namespace std;

/*
    std::unordered_set: key value, hash
        - data insert, delete, serach = TC O(1)
        - no duplicated value! if u want to multiple same numbers, std::unordered_multiset
        - if u want to compare with other by hash function, set up the keyequal
        - similiar to the std::set
*/

int main(){

    // car -> radio -> orange -> ear -> radio
    unordered_set<string> words;

    words.insert("car");
    words.insert("radio");
    words.insert("orange");
    words.insert("ear");

    string word = "radio";

    if(words.find(word)!= words.end()){
        cout<< word << " is used!" <<endl;
    }else{
        cout<< word << " is NOT used!" <<endl;
    }

    vector<int> numbers {1,5,3,1,5,7,4,5,6,3,2,7,3,6,2};
    unordered_set<int> num_set(numbers.begin(), numbers.end());
    cout<< num_set.size() << endl;
    


    return 0;
}