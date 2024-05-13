#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Person{
public:
    string name;
    int age;

    bool operator<(const Person& a) const{
        return this->age < a.age;
    }

    void print() const{
        cout<< name << ", " << age << endl; 
    }
};

int main(){
    vector<Person> v;
    v.push_back({"Amelia",29});
    v.push_back({"Noah",25});
    v.push_back({"Olivia",31});
    v.push_back({"Sophia",40});
    v.push_back({"George",35});

    sort(v.begin(), v.end());

    for(auto e:v)
        e.print();

    return 0;
}