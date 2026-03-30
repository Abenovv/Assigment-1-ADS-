#include <iostream>
using namespace std;

int pow(int a, int b) {
    int sum = 1, i = 0;
    while (i <= b) {
        sum *= b;
        i++;
    }
    return sum;
}
int f(int b, int n) {
    if (n == 0) {return 1;}
    return f(b, n-1) + pow(b,n);
}

int main(void) {
    int b = 3, n;
    cin >> n;
    cout << f(b,n) << endl;
    return 0;
}