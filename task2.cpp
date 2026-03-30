#include <iostream>
using namespace std;

int f(int n, int list[]) {
    if (n == 0) {return 0;}//base case
    return f(n - 1, list) + list[n-1];
}

int main(void) {
    int n; cin >> n;
    int list[n];
    for (int i = 0; i < n; i++) {
        cout << "Write list[" << i << "] number: ";
        cin >> list[i];
    } cout << "In general: " << f(n, list) << endl;
    return 0;
}