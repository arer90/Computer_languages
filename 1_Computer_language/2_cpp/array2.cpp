#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    // Construction uses aggregate initialization
    std::array<int, 3> a1{{1, 2, 3}}; 

    std::array<int, 3> a2 = {1, 2, 3}; 

    // Container operations are supported
    sort(a1.begin(), a1.end());
    reverse_copy(a2.begin(), a2.end(), ostream_iterator<int>(cout, " "));

    cout << '\n';

    // Ranged for loop is supported
    std::array<string, 2> a3{"E", "\u018E"};
    for (const auto& s : a3)
        cout << s << ' ';
    cout << '\n';

    // Deduction guide for array creation (since C++17)
    [[maybe_unused]] std::array<double, 3> a4{3.0, 1.0, 4.0};
    
    // Behavior of unspecified elements is the same as with built-in arrays
    [[maybe_unused]] std::array<int, 2> a5; 
    [[maybe_unused]] std::array<int, 2> a6{}; 
    [[maybe_unused]] std::array<int, 2> a7{1}; 
    return 0;
}
