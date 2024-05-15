#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    *tree traversal:
    - preorder (DFS)
    - inorder (DFS)
    - postorder (DFS)
    - level order (BFS)
            A
           /\
           B C
          /\ /\
         D E F G
        /\    \ 
        H I    J

        [1] preorder : A-> B-> D-> H-> I-> E-> C-> F-> J-> G
            ////
            void preorder(Node* node){
                if(node){
                    cout<<node->data << endl; // work or print section
                    preorder(node->left);
                    preorder(node->right);
                }
            }
            ////

        [2] inorder  : H-> D->I-> B-> E-> A-> F-> J-> C-> G
                ////
            void inorder(Node* node){
                if(node){
                    inorder(node->left);
                    cout<<node->data << endl; // work or print section
                    inorder(node->right);
                }
            }
            ////

        [3] postorder: H-> I-> D-> E-> B-> J-> F-> G-> C-> A
            ////
            void postorder(Node* node){
                if(node){
                    postorder(node->left);
                    postorder(node->right);
                    cout<<node->data << endl; // work or print section                    
                }
            }
            ////

        [4] level order: (Using Queue) A(lv0) -> B(lv1) -> C(lv1) -> D(lv2)-> E(lv2)-> F(lv2)-> G(lv2) -> H(lv3)-> I(lv3)-> J(lv3)
            ////
            void levelorder(Node* node){  // node <-- root node
                std::queue<Node*> q;
                q.push(node);

                while(!q.empty()){
                    auto curr=q.front();
                    q.pop();
                    
                    cout<< curr->data <<", ";
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                ////
                A <- B, C <- D, E <- F, G <- H,I <- J
                
                ////

            }
            ////
*/

struct Node{
    char data;
    Node* left;
    Node* right;
    
    Node(char d): data(d), left(nullptr), right(nullptr) {}
};

void preorder(Node* node){
    if(node){
        cout<<node->data << ", "; // work or print section
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node){
    if(node){
        inorder(node->left);
        cout<<node->data << ", "; // work or print section
        inorder(node->right);
    }
}

void postorder(Node* node){
    if(node){
        postorder(node->left);
        postorder(node->right);
        cout<<node->data << ", "; // work or print section                    
    }
}

void levelorder(Node* node){
    std::queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        
        cout<< curr->data <<", ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

void delete_tree(Node* node){
    if(node){
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

int main(){
    Node* root = nullptr;

    root = new Node('A');
    root->left = new Node('B');
    root->right= new Node('C');
    root->left->left = new Node('D');
    root->left->right= new Node('E');
    root->right->right=new Node('F');

    preorder(root); cout<<endl;
    inorder(root); cout<<endl;
    postorder(root); cout<<endl;
    levelorder(root); cout<<endl;
    
    delete_tree(root);
    
    return 0;
}