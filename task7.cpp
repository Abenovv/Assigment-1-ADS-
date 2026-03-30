#include <iostream>
using namespace std;

int Comparision(int n, int i, int g) {
    // function to find where space down
    if (g == i) {return 1;}
    if (g == 0) {return 0;}
    return Comparision(n,i,g-n);
}

int Cells(int n,int i = 1) {
    if (i == n*n+1) {return 0;} //base case
    cout << i << " "; //print value
    if (Comparision(n, i, n*n)) {cout << endl;} //main comparision
    return Cells(n,i+1);
}

int main(void) {
    int n; cin >> n;
    Cells(n);
    return 0;
}