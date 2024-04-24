/*
2_3. Vector

*Dynamic memory allocation --> heap memory
1. allocating the necessary memory
2. malloc() and calloc() for allocation and free by free() in C
3. new() and delete() in c++

int* ptr = new int[3];
// like array to the ptr (e.g.) ptr[0], ptr[1], ptr[2]
delete[] ptr

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    // Dynamics
    int* ptr = new int[3]{};
    ptr[0] = 10;
    ptr[1] = 20;

    for(int i=0;i<3;i++){
        cout<<ptr[i]<<'\n';
    }
    delete [] ptr;
    ptr = nullptr;
    return 0;
}