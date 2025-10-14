```cpp
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void solve(vector<string> &board, int col, int n, vector<int> &leftRow, vector<int> &upperD, vector<int> &lowerD)
{
    if (col == n)
    {
        ans++;
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (board[row][col] == '*')
            continue;
        if (leftRow[row] == 0 && upperD[n - 1 + col - row] == 0 && lowerD[row + col] == 0)
        {
            leftRow[row] = 1;
            upperD[n - 1 + col - row] = 1;
            lowerD[row + col] = 1;
            solve(board, col + 1, n, leftRow, upperD, lowerD);
            leftRow[row] = 0;
            upperD[n - 1 + col - row] = 0;
            lowerD[row + col] = 0;
        }
    }
}
int main()
{
    int n = 8;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    vector<int> leftRow(n, 0), upperD(2 * n - 1, 0), lowerD(2 * n - 1, 0);
    solve(board, 0, n, leftRow, upperD, lowerD);
    cout << ans << "\n";
    return 0;
}
```
Tags: [[Recursion]], [[CSES]]