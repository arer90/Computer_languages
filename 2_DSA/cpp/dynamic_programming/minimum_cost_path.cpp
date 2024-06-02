#include <iostream>
#include <vector>

using namespace std;

/*
    minimum cost path: start from 2(0,0) to end 5(3,3)
    map: 2->5->3->6->7->4->5
    2-7-5-4
    5-3-6-8
    7-8-7-4
    8-1-9-5

    *only right and bottom side movement (x,y) -> 
    right: (x-1,y)
    bottom: (x,y-1)
    
    *random coordinate (x,y) cost is m(x,y) and find the cost C(x,y)
        - C(x,y) = min(C(x-1,y), C(x,y-1)) + m(x,y)
    *m(x,y)             C(x,y)
    2-7-5-4             2-9-14-18
    5-3-6-8             7-10-16-24 [24, min(C(18),C(16)) + (m(x,y)=8)=24]
    7-8-7-4             14-18-23-27
    8-1-9-5             22-19-28-'32'
*/

int solution(vector<vector<int>> m){
    int rows = (int)m.size();
    int cols = (int)m[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for(int y=0;y<rows;y++){    // y-axis
        for(int x=0;x<cols;x++){
            if(x==0 && y==0) dp[y][x] = m[y][x];
            else if(x==0)    dp[y][x] = dp[y-1][x] + m[y][x];
            else if(y==0)    dp[y][x] = dp[y][x-1] + m[y][x];
            else             dp[y][x] = min(dp[y-1][x],dp[y][x-1]) + m[y][x];
        }
    }
    return dp[rows-1][cols-1];
}

int main(){
    
    vector<vector<int>> m ={
        {2,7,5,4},
        {5,3,6,8},
        {7,8,7,4},
        {8,1,9,5}
    };

    cout<< "Minimum cost: " << solution(m) <<endl;

    return 0;
}