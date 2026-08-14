# Knight Moves Grid

There is a knight on an n \times n chessboard. For each square, print the minimum number of moves the knight needs to do to reach the top-left corner.
Input
The only line has an integer n.
Output
Print the number of moves for each square.
Constraints

4 \le n \le 1000

Example
Input:
8

Output:
0 3 2 3 2 3 4 5 
3 4 1 2 3 4 3 4 
2 1 4 3 2 3 4 5 
3 2 3 2 3 4 3 4 
2 3 2 3 4 3 4 5 
3 4 3 4 3 4 5 4 
4 3 4 3 4 5 4 5 
5 4 5 4 5 4 5 6 

***idea*** : To solve this problem, we can use a dynamic programming approach. We can create a 2D array `moves` of size n x n, where `moves[i][j]` will store the minimum number of moves required for the knight to reach the top-left corner (0, 0) from the square (i, j).

We can initialize the top-left corner (0, 0) with 0 moves since the knight is already there. For all other squares, we can calculate the minimum number of moves by considering all possible knight moves from that square and taking the minimum of those moves plus one.

``` cpp code

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n, -1));

    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {-1,1,-2,2,-2,2,-1,1};

    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << '\n';
    }
}

```