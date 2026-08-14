# Grid Coloring I

You are given an n\times m grid where each cell contains one character A, B, C or D.
For each cell, you must change the character to A, B, C or D. The new character must be different from the old one.
Your task is to change the characters in every cell such that no two adjacent cells have the same character.
Input
The first line has two integers n and m: the number of rows and columns.
The next n lines each have m characters: the description of the grid.
Output
Print n lines each with m characters: the description of the final grid.
You may print any valid solution.
If no solution exists, just print IMPOSSIBLE.
Constraints

1 \le n, m \le 500

Example
Input:
3 4
AAAA
BBBB
CCDD

Output:
CDCD
DCDC
ABAB

***idea*** : 

The grid is a bipartite graph (like a chessboard).

- Cells with (i+j)%2==0 belong to one partition.
- Cells with (i+j)%2==1 belong to the other.

Since every adjacent cell belongs to the opposite partition, we can:

- Give one pair of letters to even cells.
- Give the other two letters to odd cells.

Because the two partitions use disjoint sets of letters, adjacent cells can never be equal.

``` cpp code

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i=0; i<n; i++)
    {
        cin >> grid[i];
    }


    vector<string> ans = grid;

    pair<char,char> even = {'A','B'};
    pair<char,char> odd = {'C','D'};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            pair<char,char> &p = (i+j)%2==0 ? even : odd;
            if(grid[i][j] == p.first)
            {
                ans[i][j] = p.second;
            }
            else
            {
                ans[i][j] = p.first;
            }   
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}

```