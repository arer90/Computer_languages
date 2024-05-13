#include <iostream>
#include <algorithm>
#include <vector>

#include <functional>

using namespace std;

/*
    std::sort() :
        - ascending
        - not guarantee to the same number
        - if you want to sam numbers, std::stable_sort()
        - O(nlogn)
        - vector, deque, array <useful> list, forward_list have a sortfuntion themselves
        - #include <algorithm>
*/

bool abs_cmp(const int a, const int b){
    return std::abs(a) < std::abs(b);
}

struct AbsCmp{
    bool operator()(int a, int b) const{
        return std::abs(a) < std::abs(b);
    }
};

class AbsCMP{
    public:
    bool operator()(int a, int b){
        return std::abs(a) < std::abs(b);
    }
};

int main(){
    
    int arr[5] ={4,2,3,5,1};
    sort(arr, arr+5); // ascending [1,2,3,4,5]

    for(auto e: arr)
        cout<<e<<", ";
    cout<<endl;

    vector<string> vec = {"orange", "banana","apple","lemon"};
    sort(vec.begin(), vec.end()); // ascending ["apple","banana","lemon","orange"]
    
    for(auto e: vec)
        cout<<e<<", ";
    cout<<endl;

    int arr2[5] ={7,5,3,9,1};
    sort(begin(arr2), end(arr2)); //std::begin(), std::end()
    
    for(auto e: arr2)
        cout<<e<<", ";
    cout<<endl;

    // descending
    sort(begin(arr), end(arr), greater<>()); //std::begin(), std::end()
                                // less<>()    
    for(auto e: arr)
        cout<<e<<", ";
    cout<<endl;

    sort(vec.begin(), vec.end(), greater<>()); // ascending ["apple","banana","lemon","orange"]
                                // less<>()
    for(auto e: vec)
        cout<<e<<", ";
    cout<<endl;

    // comparing
    vector<int> nums = {10,2,-3,5,7};
    sort(nums.begin(), nums.end(), abs_cmp);    // 2,-3,5,7,10 by absolute numbers
    for(auto e: nums)
        cout<<e<<", ";
    cout<<endl;

    // struct
    nums = {10,2,-3,5,7};
    sort(nums.begin(), nums.end(), AbsCmp());    // 2,-3,5,7,10 by absolute numbers
    for(auto e: nums)
        cout<<e<<", ";
    cout<<endl;

    // class
    nums = {10,2,-3,5,7};
    sort(nums.begin(), nums.end(), AbsCMP());    // 2,-3,5,7,10 by absolute numbers
    for(auto e: nums)
        cout<<e<<", ";
    cout<<endl;

    // inline bool
    struct ABScmp{
        inline bool operator()(int a, int b){
            return std::abs(a) < std::abs(b);
        }
    };
    nums = {10,2,-3,5,7};
    sort(nums.begin(), nums.end(), ABScmp());    // 2,-3,5,7,10 by absolute numbers
    for(auto e: nums)
        cout<<e<<", ";
    cout<<endl;

    // Lambda function
    nums = {10,2,-3,5,7};
    sort(nums.begin(), nums.end(), [](int a, int b){
        return std::abs(a) < std::abs(b);
    });   
    for(auto e: nums)
        cout<<e<<", ";
    cout<<endl;

    return 0;
}