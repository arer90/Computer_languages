#include <iostream>
#include <vector>

using namespace std;

// template <class T, class Allocator = std::allocator<T>>
// class vector{
//     private:
//     T* data;
//     unsigned int size;
//     unsigned int capacity;

//     /* ... */
// };

int main(){

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2(10); // v2[0] ~ v2[9]
    vector<int> v3(10,1); // v3[0]=1 ~ v3[9]=1
    vector<int> v4 {10,20,30,40,50};
    vector<int> v5(v4);
    vector<int> v6(v4.begin(), v4.begin()+3);

    for(int i=0;i<v6.size();++i){
        cout<<v6[i]<<endl;
    }

    // 2x3 matrix
    // vector<vector<int>> mat1(2, vector<int>(3,0));  // row =2 , column =3
    vector<vector<int>> mat1(2, vector<int>(3,1));  // row =2 , column =3

    // values
    vector<vector<int>> mat2 { {1,2,3}, {4,5,6} };

    for(int r=0;r<mat2.size();++r){
        for(int c=0;c<mat2[r].size();++c){
            cout<< mat2[r][c] << " ";
        }
        cout<<endl;
    }
    cout<<endl;

    /*
         *** Vector functions ***
        1. operator[]    : [O(1)] return certain element == vector.at()
        2. front()       : [O(1)] first element return
        3. back()        : [O(1)] last element return
        4. push_back()   : [O(1)] insert element from end
        5. emplace_back(): [O(1)] insert element from end but no copy
        6. pop_back()    : [O(1)] delete last element (no return)
        7. insert()      : [O(N)] insert certain position with element
        8. erase()       : [O(N)] delete certain position with element
        9. clear()       : [O(1)] delete all elements
        10. size()       : [O(1)] counting elements
        11. empty()      : [O(1)] if vector is empty, return 'true'

    */
    cout<< "Vector Capacity and function Works:" << endl;

    vector<int> vec1 {1,2,3,4};
    cout << "1. [allocation] vec1 capacity() : size() = " << vec1.capacity() << " : " << vec1.size() << endl;
    cout<< "   = ";
    for(int i=0;i<vec1.size();++i){
        cout<< vec1[i]<<" ";
    }
    cout<< endl;

    vec1.push_back(5);
    cout << "2. [push_back_5]vec1 capacity() : size() = " << vec1.capacity() << " : " << vec1.size() << endl;
    cout<< "   = ";
    for(int i=0;i<vec1.size();++i){
        cout<< vec1[i]<<" ";
    }
    cout<< endl;

    vec1.push_back(6);
    cout << "3. [push_back_6]vec1 capacity() : size() = " << vec1.capacity() << " : " << vec1.size() << endl;
    cout<< "   = ";
    for(int i=0;i<vec1.size();++i){
        cout<< vec1[i]<<" ";
    }
    cout<< endl;

    vec1.insert(vec1.begin(), 0);
    cout << "4. [insert_begin_0]vec1 capacity() : size() = " << vec1.capacity() << " : " << vec1.size() << endl;
    cout<< "   = ";
    for(int i=0;i<vec1.size();++i){
        cout<< vec1[i]<<" ";
    }
    cout<< endl;

    vec1.erase(vec1.begin()+1, vec1.begin()+3);
    cout << "5. [erase_begin()+1_begin()+3]capacity() : size() = " << vec1.capacity() << " : " << vec1.size() << endl;    
    cout<< "   = ";
    for(int i=0;i<vec1.size();++i){
        cout<< vec1[i]<<" ";
    }
    cout<< endl;


    return 0;
}