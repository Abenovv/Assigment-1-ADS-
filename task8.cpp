#include <iostream>
#include <vector>
using namespace std;

int printf(vector<vector<int>>& lst, int i = 0, int j = 0) {
    if (lst.size() == i) {return 1;}
    else if (lst[0].size() == j) {
        cout << endl; i += 1; j = 0;
        return printf(lst, i, j);}
    cout << lst[i][j] << " ";
    if (lst[0].size() == j) {cout << endl; i += 1; j = 0;}
    return printf(lst, i, ++j);
}

int checkerf(vector<vector<int>>& lst, int i = 0, int j = 0) {
    i = lst.size() - 1;
    j = lst[0].size() - 1;
    cout << "\ni = " << i << "\nj = " << j << endl;
    if (lst[i][j] == lst.size()) {return 1;}
    else {return 0;}
}

int filloutf(vector<vector<int>>& lst, int i = 0, int j = 0) {
    if () {} //base case

}

int main() {
    int i, j; cin >> i >> j; //get value
    vector<vector<int>> lst(j, vector<int>(i));

    cout << "\nlst.size() = " << lst.size();
    cout << "\nlst[0].size() = " << lst[0].size() << endl;
    cout << "\nSize of lst:\n";
    printf(lst); //just to see values

    cout << "\n\nActivation of checkerf";
    cout << checkerf(lst);

    cout << "\n\n\n";
    printf(lst);

    return 0;
}