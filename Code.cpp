#include <bits/stdc++.h>
using namespace std;
template <class T>
class MyVector {
    T* arr;
    int capacity;
    int length;
public:
    MyVector() {
        capacity = 2;
        length = 0;
        arr = new T[capacity];
    }

    void push_back(T value) {
        if (length == capacity) {
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < length; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[length++] = value;
    }
    void pop_back() {
        if (length > 0)
            length--;
    }
    int size() const {
        return length;
    }
    T& operator[](int index) {
        return arr[index];
    }
    ~MyVector() {
        delete[] arr;
    }
};
int main() {
    MyVector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << "Vector elements: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    v.pop_back();
    cout << "After pop_back: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    cout << "Current size: " << v.size() << endl;
    MyVector<string> s;
    s.push_back("Hello");
    s.push_back("World");
    cout << "String vector: ";
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
    cout << endl;
}
