#include <iostream>

using namespace std;

/*
    *tree:
    - hierarchical architecture
    - root -> branch and leaf (downside tree / \)
    - ex.) company organization, uni class, file system directory

    *structure:
    1. node : main index
    2. edge, link : 
        - connection with node and node
        - edge = parent & children hierarchical
        - if node is N, edge is N-1
    
    ex.)
         A
        /\
        B C
       /\  \
      D E   F
    *tree term:
    1. root(A) : main center and only one node
    2. parent(A) - child(B) : higher and close to the root is parent, other children
    3. leap(D,E,F) : (=terminal node / external node) no further node
    4. internal node (A,B,C) : 
    5. sibling([B,C],[D,E]) : same parent node 
    6. ancestor - descendant (D's ancestor= A,B) : parent and above all parents
    7. degree (A:2,B:2,C:1,F:0) : child's node count
    8. level (A: lv.0,[B,C]: lv.1,[D,E,F]: lv.2) : how far from root
    9. height (from D(0)'s heigh= A:2,B:1, all:2): each node's position or all node
    10. subtree : [b,d,e]

    *binary tree: max two node tree
    - every node degree must be two
    - subtree is two or empty
    - left child / right child

    *proper binary tree, full binary tree
        T         T
        /\        /\
        T T      T  T
                    /\
                    T T
    *perfect binary tree: fully filled, if height is 'h', node 2^(h+1)-1
        T
        /\
        T T
        /\ /\
        T T T T
    *complete binary tree: start to fill with left node except other parents fully filled
        T          T
        /\         /\
        T T       T  T
        /        /\  /\
        T        T T T
    *balanced binary tree: subtree's height difference is below 1
        T
        /\
        T T
       /\ /
      T T T
      /\
     T  T
    *skewed tree: except leap, all one node children

    implementation:
    [array] : completed binary tree better -> heap
    [linked_list] : it is better
        struct Node{
            char data;
            Node* left;
            Node* right;
            Node(char d): data(d), left(nullptr), right(nullptr){}
        }
*/

struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char d): data(d), left(nullptr), right(nullptr){}
};

int main(){
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right= new Node('C');
    root->left->left = new Node('D');
    root->left->right= new Node('E');
    root->right->right=new Node('F');
    
    return 0;
}