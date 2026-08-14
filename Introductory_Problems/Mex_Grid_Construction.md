# Mex Grid Construction

Your task is to construct an n \times n grid where each square has the smallest nonnegative integer that does not appear to the left on the same row or above on the same column.
Input
The only line has an integer n.
Output
Print the grid according to the example.
Constraints

1 \le n \le 100

Example
Input:
5

Output:
0 1 2 3 4
1 0 3 2 5
2 3 0 1 6
3 2 1 0 7
4 5 6 7 0

***idea*** : To solve this problem, we can use a greedy approach. We will iterate through each cell of the grid and for each cell, we will find the smallest nonnegative integer that is not present in the same row to the left and in the same column above. We can keep track of the numbers that have already been used in each row and column using sets.

``` cpp code

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<set<int>> row(n), col(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int mex = 0;
            while (row[i].count(mex) || col[j].count(mex)) {
                mex++;
            }
            grid[i][j] = mex;
            row[i].insert(mex);
            col[j].insert(mex);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

```