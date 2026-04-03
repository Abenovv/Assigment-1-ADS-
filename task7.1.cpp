#include <iostream>
#include <vector>
using namespace std;

int Fillf(int lst[4][4], int n, int i = 0, int j = 0) {
    if (i == n) {return 0;}
    lst[i][j] = 0;
    if (j == n-1) {
        j = 0; return Fillf(lst, n, i + 1, j);}
    else {return Fillf(lst, n, i, j + 1);}
}
int Upf(int lst[4][4], int n, int i = 0, int j = 0, int counter = 1);
int printf(int lst[4][4], int n, int i = 0, int j = 0) {
    if (i == n) { return 0;}
    cout << lst[i][j] << " ";
    if (j == n-1) {
        j = 0;
        cout << endl;
        return printf(lst, n, i + 1, j);
    }
    else {
        return printf(lst, n, i, j + 1);
    }
}

int Downf(int lst[4][4], int n, int i, int j, int counter) {
    if (j + 1 == i) {
        i = j;
        j = 1;
        return Upf(lst, n, i, j);
    }
    lst[i][j] = counter;
    return Downf(lst, n, i+1, j, counter + 1);}

int Upf(int lst[4][4], int n, int i, int j, int counter) {
    if ((n-i) == j) {
        cout << endl;
        return Downf(lst, n, i+1, j-1, counter);
    }
    lst[i][j] = counter;
    return Upf(lst, n, i, j+1, counter + 1);
}


int main() {
    int n = 4;
    int lst[4][4];
    Fillf (lst, n);
    Upf(lst, n);
    printf(lst, n);
    return 0;
}