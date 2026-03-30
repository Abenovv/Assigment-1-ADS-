#include <iostream>
using namespace std;

int Filling(int l[], int i = 0) {
    if (n)
    return Filling(l, i+1);
}

int main(void) {
    int n; cin >> n;
    int top[n], bottom[n-1], right[n-1], left[n-2], center[n-2];
    int sum = n*n;
    int l[sum]; // l - list
    Filling();
    cout << l;
    return 0;
}