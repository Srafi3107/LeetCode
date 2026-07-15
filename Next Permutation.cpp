#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {1, 2, 3};

    do {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    } while (next_permutation(arr, arr + 3));

    return 0;
}
