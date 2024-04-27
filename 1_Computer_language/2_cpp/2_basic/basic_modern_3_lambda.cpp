#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
    string name;
    int age;
};

/*

lambda expression : C++11 no name object, 
replacement for function pointer and function object
'[]' <- lambda expression used following codes;
'()' <- variables
'{}' <- return with algorithms

*/


int main(){

    auto square = [](double a){return a*a;};
    cout << "square(1.414) = " << square(1.414) << endl;

    vector<Person> students;
    students.push_back({"Kim",20});
    students.push_back({"Lee",30});
    students.push_back({"Park",24});
    students.push_back({"Choi",50});

    sort(students.begin(), students.end(),
            /*
            *bool cmp(p1, p2){}
            */
            [](const Person& p1, const Person& p2)
            {
                // Ascending order by names
                return p1.name < p2.name;
            }
        );

    for(const auto& p: students){
        cout << p.name << " : " << p.age << endl;
    }

    return 0;
}