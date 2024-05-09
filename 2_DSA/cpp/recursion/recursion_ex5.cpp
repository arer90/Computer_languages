#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    permutation : using n element to make up the subgroups
    ex.)
    {a,b,c,d}
    = a, {b,c,d}
    = b, {a,c,d}
    = c, {a,b,d}
    = d, {a,b,c}

    step.)
    1. swap with first element to each index
    2. except first element, using rest of swap function
*/
template<typename T>
void print_vector(const vector<T>& vec){
    for(const auto& e: vec)
        cout<<e<<" ";
    cout<<endl;
}

void permutation(vector<int>& vec, int k){ // '&' reference
    if(k==vec.size()-1){
        print_vector(vec);
        return;
    }
    for(int i=0;i<vec.size();++i){
        swap(vec[k],vec[i]);
        permutation(vec,k+1);
        swap(vec[k], vec[i]); // series continuous
        /*
            1step - 1,(2,3,4),
            2step - 2,(1,3,4),
            3step - 3,(2,1,4),
            4step - 4,(2,3,1),
        */

    }
}

int main(){
    vector<int> vec {1,2,3,4};
    permutation(vec, 0);

    cout<<endl;

    vector<int> vec2 {4,2,3,1};
    sort(vec2.begin(), vec2.end());
    do{
        print_vector(vec2);
    }while(next_permutation(vec2.begin(), vec2.end()));

    return 0;
}