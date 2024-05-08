#include <iostream>

using namespace std;

string reverse(const string& str){
    if(str.length() == 0)
        return "";
    else
        return reverse(str.substr(1))+str[0];
        // 'str.substr(1)' return substring character by idx=1
}

int main(){

    cout<< reverse("hello") << endl;
    
    
    return 0;
}