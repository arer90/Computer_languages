#include <iostream>
#include <vector>

using namespace std;

/*
    graph: G = (V,E)
    - V : vertex, node
        = basic node
        = storing values
    - E : edge, link
        = connection between nodes
        = having a direction
        = having a weight

    *function:
    - weight: edge's cost
    - adjacent vertex: the condition with edge's connection in nodes
    - degree: the condition with node's connection in nodes
    - path: from certain node's to node movement as adjacent vertex way
    - cycle: 
        [1] simple path from start from end node
        [2] tree: no cycle in graph
    
    *function2:
    - directed graph: like network, (u,v) in directed graph => (u,v) =/= (v,u)
    - weighted graph: edge's weight with graph
    - subgraph: partial graph

    *function3:
    - adjacency matrix: N x N matrix size, adj[u][v], if graph node is small and edge is a lot, 
        * space complexity O(n^2)
        * ex.)
                vector<vector<int>> adj matrix={
                    {0,1,0,1,1,0},
                    {0,1,0,1,1,0},
                    {0,1,0,1,1,0},
                    {0,1,0,1,1,0},
                    {0,1,0,1,1,0}
                };
    - adjacency list: 
        *each node's connection by linked list
        * space complexity O(N+M) (N: node's count, M: edge's count)
        * ex.)
        *       <adjacency list>
                vector<vector<int>> adj_matrix={
                    {1,3,4},
                    {0,2,4},
                    {1,5},
                    {0,4},
                    {0,1,3},
                    {2}
                };
        *       <edge list>
                vector<vector<int>> edge_matrix={
                    {0,1},{0,3},{0,4},
                    {1,0},{1,2},{1,4},
                    {2,1},{2,5},
                    {3,0},{3,4},
                    {4,0},{4,1},{4,3},
                    {5,2},
                };
*/

vector<vector<int>> get_adj_list(vector<vector<int>>& adj_matrix){
    vector<vector<int>> adj_list(adj_matrix.size());
    for(int u=0;u<adj_matrix.size();u++){
        for(int v=0;v<adj_matrix[u].size();v++){
            if(adj_matrix[u][v]==1){
                adj_list[u].push_back(v);
            }
        }
    }
    return adj_list;
}

int main(){
    // adjacency matrix
    vector<vector<int>> adj_matrix={
        {0,1,0,1,1,0}, // 0 0 1 2 3 4 5 
        {1,0,1,0,1,0}, // 1
        {0,1,0,0,0,1}, // 2
        {1,0,0,0,1,0}, // 3
        {1,1,0,1,0,0}, // 4
        {0,0,1,0,0,0}, // 5
    };

    // // adjacency list
    // vector<vector<int>> adj_matrix={
    //     {1,3,4},
    //     {0,2,4},
    //     {1,5},
    //     {0,4},
    //     {0,1,3},
    //     {2},
    // };

    vector<vector<int>> adj_list = get_adj_list(adj_matrix);
    
    for(const auto& l: adj_list){
        for(const auto n: l)
            cout<< n << ", ";
        cout<<endl;
    }



    return 0;
}