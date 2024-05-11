#include <iostream>
#include <algorithm>

using namespace std;

/*
    input data : 5,3,4,2,1
    ascending order : 1,2,3,4,5
    descending order : 5,4,3,2,1

    list of sort functions:
    [1] bubble sort
    [2] selection sort
    [3] insertion sort
    ---------------------simple but O(n^2) in worst case
    [4] shell sort
    [5] merge sort
    [6] quick sort
    [7] heap sort
    [8] radix sort
    ---------------------complicated but O(nlogn) or O(n) in worst case

    Q. What is points to evaluate the sort function?
    A)  1. counting of comparing and movement
        2. there is no optimal function and only fitting functions
    
    Point. Stable sorting function
    - stable sorting : same value with series of element after sorting
    - unstable sorting : different value with series of element after sorting
*/

void bubble_sort(int data[], int n){        // O(n^2)
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(data[j]<data[j-1]){
                swap(data[j], data[j-1]);
            }
        }
    }
}

void selection_sort(int data[], int n){     // O(n^2)
    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n>i;j++){
            if(data[j]<data[idx]){
                idx=j;
            }
        }
        swap(data[i], data[idx]);
    }
}

void insertion_sort(int data[], int n){     // O(n^2)
    for(int i=0;i<n;i++){
        int key = data[i];
        int j=i-1;
        while(j>=0 && data[j]>key){
            data[j+1] = data[j];
            j--;
        }
        data[j+1]=key;
    }
}


int main(){

    int data[] = {4,2,3,5,1};
    bubble_sort(data,5);
    // selection_sort(data,5);
    // insertion_sort(data,5);

    for(auto n: data)
        cout<< n <<", ";
    cout<<endl;

    return 0;
}