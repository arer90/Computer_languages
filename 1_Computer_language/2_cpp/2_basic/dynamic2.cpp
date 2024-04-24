#include <iostream>

using namespace std;

template <typename T>
class DynamicArray {
private:
    unsigned int sz;
    // int *arr;
    T *arr;

public:
    explicit DynamicArray(int n) : sz(n) {
        arr = new int[sz]{};
    }

    DynamicArray(const DynamicArray& other) : sz(other.sz) {
        arr = new int[sz];
        for (unsigned int i = 0; i < sz; ++i) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] arr;
            sz = other.sz;
            arr = new int[sz];
            for (unsigned int i = 0; i < sz; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    unsigned int size() const {
        return sz;
    }

    // int& operator[](int i) {
    //     if (i < 0 || i >= sz) {
    //         throw out_of_range("Index out of range");
    //     }
    //     return arr[i];
    // }
    T& operator[](int i) {
        if (i < 0 || i >= sz) {
            throw out_of_range("Index out of range");
        }
        return arr[i];
    }

    // const int& operator[](int i) const {
    //     if (i < 0 || i >= sz) {
    //         throw out_of_range("Index out of range");
    //     }
    //     return arr[i];
    // }
    const T& operator[](int i) const {
        if (i < 0 || i >= sz) {
            throw out_of_range("Index out of range");
        }
        return arr[i];
    }
};

int main() {
    DynamicArray<int> da(5);
    da[0] = 10;
    da[1] = 20;
    da[2] = 30;

    for (int i = 0; i < da.size(); ++i) {
        cout << da[i] << " ";
    }
    cout << endl;

    return 0;
}
