```cpp
void solve(vector<string> &board, vector<vector<string>> &boards, int col, int n, vector<int> &leftRow, vector<int> &upperD, vector<int> &lowerD)
{
    if (col == n)
    {
        boards.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && upperD[n - 1 + col - row] == 0 && lowerD[row + col] == 0)
        {
            leftRow[row] = 1;
            upperD[n - 1 + col - row] = 1;
            lowerD[row + col] = 1;
            board[row][col] = 'Q';
            solve(board, boards, col + 1, n, leftRow, upperD, lowerD);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperD[n - 1 + col - row] = 0;
            lowerD[row + col] = 0;
        }
    }
}
int main()
{
    vector<vector<string>> boards;
    int n = 20;
    vector<string> board(n, string(n, '.'));
    print(boards);
    vector<int> leftRow(n, 0), upperD(2 * n - 1, 0), lowerD(2 * n - 1, 0);
    solve(board, boards, 0, n, leftRow, upperD, lowerD);
    return 0;
}
```