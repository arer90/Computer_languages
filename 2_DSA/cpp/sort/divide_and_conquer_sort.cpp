#include <iostream>
#include <algorithm>

using namespace std;

/*
    [1] merge sort : unordered list -> separate into two section
                -> partially sorting by recursion
                -> merging two sorted section
        - 1. separte and merge : O(logn)
        - 2. merging all section : O(n)
        - 3. all time complexity : O(nlogn)
    
        *character
        - 1. not first all section, only partially parts can be sorted
        - 2. stable and do not get any impact by first time
        - 3. (cons) it is necessary to extra space (space complexity: O(n))
    
    [2] quick sort : division and conquer sorting, 
                -> using 'pivot', and find max and min value
                -> recursion to division and conquer sections
        
        1. best case : O(nlogn)
        2. worst case: O(n^2)

        *character
        - 1. pivot is the key of sorting in quick sort
        - 2. unstable sort and great impact on calculation by initial sort setting
        - 3. noramally best sorting algorithm
*/
int buff[256];

void merge(int data[], int left, int mid, int right){
    int i=left, j=mid+1, k=left;
    
    while(i<=mid && j<=right){
        if(data[i]<=data[j])
            buff[k++] = data[i++];
        else
            buff[k++] = data[j++];
    }
    while(i<=mid)
        buff[k++] = data[i++];
    while(j<=right)
        buff[k++] = data[j++];
    for(int x=left;x<=right;x++)
        data[x] = buff[x];
}

void merge_sort(int data[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(data, left, mid);
        merge_sort(data, mid+1, right);
        merge(data, left, mid, right);
    }
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int partition(int data[], int left, int right){
    int pivot = data[left];
    int i=left+1, j=right;

    while(1){
        while(data[i] <= pivot && i<=right)
            i++;
        while(data[j] > pivot && j > left)
            j--;
        if(i<j)
            swap(data[i], data[j]);
        else
            break;
    }
    swap(data[left], data[j]);
    return j;
}

void quick_sort(int data[], int left, int right){
    if(left<right){
        int p = partition(data, left, right);
        quick_sort(data, left, p-1);
        quick_sort(data, p, right);
    }
}

int main(){
    int data[] = {2,6,7,4,1,8,5,3};
    merge_sort(data, 0,7);
    for(const auto& n: data)
        cout<<n<<", ";
    cout<<endl;

    int data2[]={5,6,7,3,1,9,2,4,8};
    quick_sort(data2, 0, size(data2)-1);
    for(const auto& n: data2)
        cout<<n<<", ";
    cout<<endl;

    return 0;
}