#include <iostream>
using namespace std;

int f(int n) {
    if (n == 0) {return 0;}
    return f(n - 2) + n;
}
int main(void) {
    int n; cin >> n;
    if (n % 2 == 1) {
        n = n - 1;
    }
    cout << f(n) << endl;
    return 0;
}