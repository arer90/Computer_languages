#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    *lienar search:
    - search from first to end
    - Time complexity : O(n)
    pros) easy and useful to the any dat
    cons) inefficient

    *binary search:
    - separate into two section to find out a value in sorted array 
        with ascending orders
    pros) fastest search
    cons) only sorted array

    *std::binary_search <- #include <algorithm>
    - sorted order array - (first,last, comp)

*/

bool linear_search(int data[], int n, int target){
    for(int i=0;i<n;i++){
        if(data[i]==target)
            return true;
    }
    return false;
}

bool binary_search(int data[], int n, int target){
    int low=0;
    int high=n-1;

    if(data[low] > target || data[high] < target)
        return false;

    while(low<=high){
        int mid=(low+high)/2;
        if(data[mid]==target)
            return true;
        else if(data[mid]<target)
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
}

int main(){
    int data[] = {1,2,3,5,7,10,13,15,18,23,25,27,28,30,33};
    int target = 23;

    bool res1 = linear_search(data, std::size(data), target);
    bool res2 = binary_search(data, std::size(data), target);
    bool res3 = binary_search(begin(data),end(data), target);

    cout<< "Targe available? (T:1, F:0): "<<endl;
    cout<< res1 << endl;
    cout<< res2 << endl;
    cout<< res3 << endl;

    return 0;
}