#include <iostream>
using namespace std;

int rf(int n) {
    if (n == 1) {return 1;}
    cout << n << " ";
    return rf(n - 1);
}
int main(void) {
    int n; cin >> n;
    cout << rf(n);
    return 0;
}