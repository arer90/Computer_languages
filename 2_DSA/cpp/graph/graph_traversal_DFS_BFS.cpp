#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*
    Graph traversal: 
    *[DFS] (Depth First Search)
        - one node to another node track repeatidly until no process
        and if there is no path, algorithm starts a 'backtracking' to find
        another path
        - search method: start to far away (deepest way)
        - recursion or stack
        - ex) DFS (0,1,2,5,4,3)
            0 - 1 - 2
            | \ |   |
            3 - 4   5
    
    *[BFS] (Breadth First Search)
        - one node to another node to track near side
        - search method: start from close to far away (nearest way)
        - queue    0,3,4,1,2,5)
        - ex) BFS (0,1,3,4,2,5)
            0 - 1 - 2
            | \ |   |
            3 - 4   5
*/

const int N=6;
bool gVisited[N] = {};

void dfs_recursion(const vector<vector<int>>& adj_list, int s){
    if(gVisited[s])
        return;
    
    gVisited[s] = true;
    cout<< s << ", ";
    
    for(int v: adj_list[s])
        dfs_recursion(adj_list,v);
}

vector<int> dfs(const vector<vector<int>>& adj_list, int s){
    vector<bool> visited(adj_list.size(), false);
    vector<int> visit_order;
    stack<int> stk;
    stk.push(s);

    while(!stk.empty()){
        int v = stk.top();
        stk.pop();

        if(visited[v]) continue;

        visited[v] = true;
        visit_order.push_back(v);

        for(int a: adj_list[v]){
            if(!visited[a]){
                stk.push(a);
            }
        }
    }
    return visit_order;
}

vector<int> bfs(const vector<vector<int>>& adj_list, int s){
    vector<bool> visited(adj_list.size(), false);
    vector<int> visit_order;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(visited[v]) continue;

        visited[v] = true;
        visit_order.push_back(v);

        for(int a: adj_list[v]){
            if(!visited[a]){
                q.push(a);
            }
        }
    }
    return visit_order;
}

void vprint(vector<int> in){
    for(const auto& a: in){
        cout<< a <<", ";
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> adj_list = {
        {1,3,4},
        {0,2,4},
        {1,5},
        {0,4},
        {0,1,3},
        {2}
    };
    dfs_recursion(adj_list, 0);
    cout<<endl;

    auto dfs_order = dfs(adj_list,0);
    auto bfs_order = bfs(adj_list,0);

    vprint(dfs_order);
    vprint(bfs_order);

    return 0;    
}