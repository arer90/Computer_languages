/*
2_2. array

1. Directly search the element by index: O(1)
2. Cache locality - element of array connects to next each other and can search them locally
3. Constant and constant values's size cannot be changed by using array after initializing
4. Allocated stack memory by (regularly) 1MB
5. 

---- 
*What if high dimension?
int matrix[i][j] -> First i search -> Second j search
int matrix[2][3] ={ {1,2,3},{4,5,6}}

Think :
matrix[0][0] matrix[0][1] matrix[0][2]
matrix[1][0] matrix[1][1] matrix[1][2]

Computer:
matrix[0][0] 
matrix[0][1] 
matrix[0][2]
matrix[1][0] 
matrix[1][1] 
matrix[1][2]
----
template<class T, std::size_t N>
struct array

**Disadvantage:
[1] size of array must be fixed
[2] stack memory only
[3] cannot dynamic allocation -> vector

*/

#include <iostream>
#include <array> // array template
using namespace std;

int main(){

    int score[5] = {90,90,90,90,90};
    int score_size = sizeof(score) / sizeof(score[0]);
    // int score_size = std::size(score);
    array<int, 5> second_arr = {50,60,70,80,90};


    ////////////////////////////////////
    int s = 0;
    for (int i=0;i<score_size;i++){
        s += score[i];
    }
    float m = (float) s/score_size;
    cout<<m<<'\n';
    
    
    ////////////////////////////////////
    int s2 = 0;
    for(int i=0;i<second_arr.size();i++){
        s2 += second_arr[i];
    }
    float m2 = (float) s2/second_arr.size();
    cout<<m2<<'\n';

    return 0;
}