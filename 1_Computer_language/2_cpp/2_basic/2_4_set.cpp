#include <iostream>
#include <set>

using namespace std;

int main(){
    unsigned int x = 2;
    int y;
    // x = x << 1;
    x = x << 2;
    y = 4;
    x = x | y;
    
    cout<<x<<endl;
    return 0;
}