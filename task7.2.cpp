#include <iostream>
using namespace std;

int FillOutf(int lst[4][4], int n, int i = 0, int j = 0) {
    if (n == i) {return 1;}
    lst[i][j] = 0;
    if (n == j) {
        i++; j = 0;
        return FillOutf(lst, n, i, j);
    }
    return FillOutf(lst, n, i, j + 1);
}
int printf(int lst[4][4], int n, int i = 0, int j = 0) {
    if (n == i) {return 1;}
    cout << lst[i][j] << " ";
    if ((n - 1) == j) {
        i += 1; j = 0;
        cout << endl;
        return printf(lst, n, i, j);
    }
    else {return printf(lst, n, i, j + 1);}
}
int checkf(int lst[4][4], int N) {
    if (N % 2 != 0) {
        cout << "N: " << N << endl;
        if (lst[N - 2][N - 2] == 0) {return 1;}
        else {return 0;}
    }
    else if (N % 2 == 0) {
        if (lst[N-N/2][N-N/2-1] != 0) {cout << "\nFull gone\n"; return 0;}
        else {return 1;}
    }
} //unfinished

int topf(int lst[4][4], int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1, int loop = 0);
int rightf(int lst[4][4], int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1);
int bottomf(int lst[4][4], int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1);
int leftf(int lst[4][4], int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1);

int topf(int lst[4][4], int n, int N, int i, int j, int counter, int cycle, int loop) {
    if (checkf(lst, N) && (n == j)) {
        j = j - loop; cout << "moved to right from top\n";
        return rightf(lst, n, N, i + 1, j - 1, counter, cycle);
    }
    lst[i][j] = counter;
    cout << "i = " << i << " j = " << j << " | " << endl;
    return topf(lst, n, N, i, j + 1, counter + 1, cycle, loop);
}
int rightf(int lst[4][4], int n,int N, int i, int j, int counter, int cycle) {
    if (n == i) {
        cout << "moved to bottom from right\n";
        return bottomf(lst, n, N, i - 1, j - 1, counter);
    }
    cout << "i = " << i << " j = " << j << " | " << endl;
    lst[i][j] = counter;
    return rightf(lst, n, N, i + 1, j, counter + 1, cycle);
}
int bottomf(int lst[4][4], int n, int N, int i, int j, int counter, int cycle) {
    if ((cycle - 2) == j && checkf(lst, N)) {
        j = 0; cout << "moved to left from bottom\n";
        return leftf(lst, n, N, i - 1, j, counter, cycle);
    } else if (!checkf(lst, N)) {return 0;}
    cout << "i = " << i << " j = " << j << " | " << endl;
    lst[i][j] = counter;
    return bottomf(lst, n, N, i, j - 1, counter + 1, cycle);
}
int leftf(int lst[4][4], int n, int N, int i, int j, int counter, int cycle) {
    if ((cycle - 1) == i) {
        cout << "moved to topf cycle2 from left\n";
        return topf(lst, n - 1, N, i + 1, j + 1, counter, cycle + 1);
    }
    cout << "i = " << i << " j = " << j << " | " << endl;
    lst[i][j] = counter;
    return leftf(lst, n, N, i - 1, j, counter + 1, cycle);
} //unfinished


int main() {
    int n = 4;
    int lst[4][4];
    FillOutf(lst, n);
    printf(lst, n);
    cout << endl;
    topf(lst, n, n);
    printf(lst, n);
}