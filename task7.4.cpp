#include <iostream>
#include <vector>
using namespace std;

int FillOutf(vector<vector<int>>& lst, int n, int i = 0, int j = 0) {
    if (n == i) {return 1;}
    lst[i][j] = 0;
    if (n == j) {
        i++; j = 0;
        return FillOutf(lst, n, i, j);
    }
    return FillOutf(lst, n, i, j + 1);
}
int printf(vector<vector<int>>& lst, int n, int i = 0, int j = 0) {
    if (n == i) {return 1;}
    cout << lst[i][j] << " ";
    if ((n - 1) == j) {
        i += 1; j = 0;
        cout << endl;
        return printf(lst, n, i, j);
    }
    else {return printf(lst, n, i, j + 1);}
}
int checkf(vector<vector<int>>& lst, int N) {
    if (N % 2 != 0) {
        if (lst[N/2-1/2][N/2-1/2] == 0) {return 1;}
        else {return 0;}
    }else if (N % 2 == 0) {
        if (lst[N-N/2][N-N/2-1] != 0) {return 0;}
        else {return 1;}
    }
}

int topf(vector<vector<int>>& lst, int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1);
int rightf(vector<vector<int>>& lst, int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1);
int bottomf(vector<vector<int>>& lst, int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1);
int leftf(vector<vector<int>>& lst, int n, int N, int i = 0, int j = 0, int counter = 1, int cycle = 1);

int topf(vector<vector<int>>& lst, int n, int N, int i, int j, int counter, int cycle) {
    if (checkf(lst, N) && (n == j)) {
        return rightf(lst, n, N, i + 1, j - 1, counter, cycle);
    } else if (!checkf(lst, N)) {return 1;}
    lst[i][j] = counter;
    return topf(lst, n, N, i, j + 1, counter + 1, cycle);
}
int rightf(vector<vector<int>>& lst, int n,int N, int i, int j, int counter, int cycle) {
    if (n == i) {return bottomf(lst, n, N, i - 1, j - 1, counter, cycle);}
    lst[i][j] = counter; return rightf(lst, n, N, i + 1, j, counter + 1, cycle);
}
int bottomf(vector<vector<int>>& lst, int n, int N, int i, int j, int counter, int cycle) {
    if ((cycle - 2) == j && checkf(lst, N)) {
        return leftf(lst, n, N, i - 1, j + 1, counter, cycle);
    } else if (!checkf(lst, N)) {return 0;}
    lst[i][j] = counter;
    return bottomf(lst, n, N, i, j - 1, counter + 1, cycle);
}
int leftf(vector<vector<int>>& lst, int n, int N, int i, int j, int counter, int cycle) {
    if ((cycle - 1) == i) {
        return topf(lst, n - 1, N, i + 1, j + 1, counter, cycle + 1);
    }
    lst[i][j] = counter;
    return leftf(lst, n, N, i - 1, j, counter + 1, cycle);
} //unfinished


int main() {
    int n; cin >> n;
    vector<vector<int>> lst(n, vector<int>(n, 0));;

    FillOutf(lst, n);
    printf(lst, n);
    cout << endl;

    topf(lst, n, n);
    printf(lst, n);
}