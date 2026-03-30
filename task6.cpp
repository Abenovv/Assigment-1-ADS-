#include <iostream>
#include <string>
using namespace std;

int rf(int n, string list[]) {
    if (n == 0) {return 0;}
    cin >> list[n-1];
    return rf(n-1, list);
}

int print(int n,string list[], int i = 0) {
    if (n == i) {return 0;}
    cout << list[i] << endl;
    return print(n,list,i+1);
}

int main(void) {
    int n; cin >> n;
    string list[n];
    rf(n, list);
    print(n, list);
    return 0;
}