#include <iostream>

using namespace std;

int main(){
    enum color {red=10, blue=20, yellow=30} mycolor;
    mycolor = red;
    cout<<mycolor<<endl;
    typedef int num;
    num counts = 3;
    cout<<counts<<endl;

    cout<<sizeof(long)<<endl;
    cout<<sizeof(long double)<<endl;

    return 0;
}