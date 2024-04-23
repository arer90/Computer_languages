#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    // C language - malloc(), calloc(), free()
    // C++ language - new, delete
    int *ptr = new int[3] {};   // {} is allocating zero value
    ptr[0] = 10;
    ptr[1] = 20;

    for(int i=0;i<3;++i)
    cout << ptr[i] << endl;

    delete [] ptr;
    ptr = nullptr;

    return 0;
}