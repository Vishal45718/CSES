# Chessboard and Queens
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example
Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:

65

***idea*** : To solve this problem, we can use a backtracking algorithm to explore all possible placements of the queens on the chessboard. The algorithm will recursively attempt to place a queen in each row, ensuring that no two queens threaten each other.

```cpp code

#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<string> &board, vector<int> &col, vector<int> &diag1, vector<int> &diag2, int row, int &count)
{
    if(row == 8)
    {
        count++;
        return;
    }
    for(int c=0; c<8; c++)
    {
        if(board[row][c] == '.' && col[c] == 0 && diag1[row+c] == 0 && diag2[row-c+7] == 0)
        {
            col[c] = diag1[row+c] = diag2[row-c+7] = 1;
            backtrack(board, col, diag1, diag2, row+1, count);
            col[c] = diag1[row+c] = diag2[row-c+7] = 0;
        }
    }
}

int main()
{
    int count = 0;
    vector<string> board(8);
    for(int i=0; i<8; i++)
    {
        cin >> board[i];
    }
    vector<int> col(8, 0);
    vector<int> diag1(15, 0);
    vector<int> diag2(15, 0);
    backtrack(board, col, diag1, diag2, 0, count);
    cout << count << endl;
    return 0;
}


```