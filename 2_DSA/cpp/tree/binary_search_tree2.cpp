#include <iostream>

using namespace std;

/*
    binary search tree remove:
    - after removing the node, it is necessary to change with
        thesuitable node
    - case1 : no child node : removing node link
    - case2 : only one child noe : removing the node and change
                                    parent node's to the this node
    - case3 : two child node : descent value to current node and delete descent
                                -> successor

    [case1]: erase(4)
            10                          10
            /\                          /\
            5 14                        5 14
           /\ /\                        \ /\  
          4 7 12 18        =>           7 12 18
            /\    /\                    /\    /\
            6 9  16 20                  6 9  16 20 
    [case2]: erase(5) (after erase(4))
            10                          10
            /\                          /\
            5 14                       7  14
            \ /\                      /\   /\  
            7 12 18        =>        6 9  12 18
            /\    /\                         /\
            6 9  16 20                      16 20 
    [case3]: erase(14) -> insert(15)
            10                           10                    
            /\                           /\         
           7  14                        7  16      
          /\   /\                      /\  /\    
         6 9  12 18                   6 9 12 18 
                 /\                          /\ 
                16 20                       15 20  
        12: predecessor
        14: successor
    [case3]: erase(10)
            10                           12                    
            /\                           /\         
           7  16                        7  16      
          /\   /\                      /\  /\    
         6 9  12 18                   6 9 15 18 
                 /\                           \ 
                15 20                         20 
    

    **O(h) -> log_2(n)
*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{
    private:
        Node* root = nullptr;
    public:
        ~BinarySearchTree(){
            delete_tree(root);
        }
        void insert(int value){
            if(!root)
                root = new Node(value);
            else
                insert_impl(root, value);
        }
        Node* find(int value){
            return find_impl(root, value);
        }
        void inorder(){
            inorder_impl(root);
        }
        void erase(int value){
            root = erase_impl(root, value);
        }

    private:
        void insert_impl(Node* curr, int value){
            if(value<curr->data){
                if(!curr->left)
                    curr->left = new Node(value);
                else
                    insert_impl(curr->left, value);
            }else{
                if(!curr->right)
                    curr->right = new Node(value);
                else
                    insert_impl(curr->right,value);
            }
        }

        Node* find_impl(Node* curr, int value){
            if(curr==nullptr)
                return nullptr;
            if(value==curr->data)
                return curr;
            else{
                if(value<curr->data)
                    return find_impl(curr->left, value);
                else
                    return find_impl(curr->right, value);
            }
        }

        void inorder_impl(Node* curr){
            if(curr!=nullptr){
                inorder_impl(curr->left);
                cout<<curr->data << ", ";
                inorder_impl(curr->right);
            }
        }

        void delete_tree(Node* node){
            if(node){
                delete_tree(node->left);
                delete_tree(node->right);
                delete node;
            }
        }

        Node* erase_impl(Node* node, int value){
            if(!node)
                return nullptr;
            
            if(value < node->data)
                node->left = erase_impl(node->left, value);
            else if(value > node->data)
                node->right = erase_impl(node->right, value);
            else{
                if(node->left && node->right){
                    // two child node
                    auto succ = successor(node);
                    node->data = succ->data;
                    node->right= erase_impl(node->right, succ->data);
                }else{
                    // only one child or no child node
                    auto tmp = node->left ? node->left:
                                        node->right;
                    delete node;
                    return tmp;
                }                
            }
            return node;
        }

        Node* successor(Node* node){
            auto curr = node->right;
            while(curr && curr->left)
                curr = curr->left;
            return curr;
        }
};

int main(){
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(14);
    bst.insert(5);
    bst.insert(7);
    bst.insert(18);
    bst.insert(4);
    bst.insert(6);
    bst.insert(20);
    bst.insert(16);
    bst.inorder();
    cout<<endl;

    if(bst.find(7))
        cout<< "7 is found" << endl;
    else
        cout<< "7 is not found" << endl;
    
    if(bst.find(15))
        cout<< "15 is found" << endl;
    else
        cout<< "15 is not found" << endl;

    bst.insert(9);
    bst.insert(12);
    bst.inorder();
    cout<<endl;

    bst.erase(4);
    bst.erase(5);
    bst.erase(14);
    bst.inorder(); cout<<endl;

    bst.insert(15);
    bst.erase(10);
    bst.inorder(); cout<<endl;

    return 0;

    /*
        - BST -
        *cons:  1. element series insertion 
                2. if tree skewed, tree height = n-1 amd
                    traversal, insert, remove: O(n)
        
        *solution: AVL tree, red-black tree, b-tree, splay tree
    */
}