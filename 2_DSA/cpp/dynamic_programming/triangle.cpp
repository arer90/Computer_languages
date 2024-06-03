#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    triangle limits: 
    [1] height 1 ~ 500
    [2] numbers 0 ~ 9999 
    [3] chk size = 500 * 10000 = 5,000,000

    7,
    3,8,
    8,1,0,
    2,7,4,4,
    4,5,2,6,5,

    *soution idea(2): 
    - random (x,y) has a tri(x,y) value
    - the sum of int value to top (x,y)
    - dp(x,y) = max(dp(x-1, y-1), dp(x,y-1))+tri(x,y)

    *solution idea(3):
    - starting from top(x,y) to left and right side and top to bottom dp(x,y)
    - until bottom dp(x,y)
*/

int solution(vector<vector<int>> triangle){
    /*
    -triangle-
    7,
    3,8,
    8,1,0,
    2,7,4,4,
    4,5,2,6,5,

    -dp-
    7,
    3,8,
    8,1,0,
    2,7,4,4,
    4,5,2,6,5,
    */

    vector<vector<int>> dp = triangle;
    int n = triangle.size();

    for(int y=1;y<n;y++){   // start from 1 because of (x,y) = (0,0) is not going to change
        for(int x=0;x<=y;x++){  // 
            if(x==0)    // left side 
                dp[y][x] = dp[y-1][x] + triangle[y][x];
            else if(x==y)   // right side
                dp[y][x] = dp[y-1][x-1] + triangle[y][x];
            else
                dp[y][x] = max(dp[y-1][x-1],dp[y-1][x]) + triangle[y][x];

        }
    }
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}

int main(){
    vector<vector<int>> tri {
        {7},
        {3,8},
        {8,1,0},
        {2,7,4,4},
        {4,5,2,6,5}
    };

    cout<< solution(tri) << endl;
    return 0;
}