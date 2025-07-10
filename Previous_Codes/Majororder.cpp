#include <iostream>
using namespace std;

int main() {
    int arr[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    int *ptr = arr[0];
    cout<< *(ptr + 1*3 + 1);
    int value = *(*(arr + 1) + 1);
    cout<< value; //same as above
    return 0;
}
