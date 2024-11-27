## Question Statement
Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:
1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.
**Note:**
>- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
>- Only the filled cells need to be validated according to the mentioned rules.
## Example
Example 1:
![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
>**Input:** board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
>**Output:** true

Example 2:
>**Input:** board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
>**Output:** false
>**Explanation:** Same as Example 1, except with the **5** in the top left corner being modified to **8**. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
## Approach
This problem does not focus on the solvability of the sudoku, but only it's current validity. In order to make sure that it is a valid sudoku, we need to check all rows, cols and 3x3 squares. Each row, col and 3x3 square must have only unique elements. In order to achieve that we can use a map and set. For the 3x3 squares we reduce the indices by 3 so that we check for unique elements in those subsquares.
## Code
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<char>> rows, cols;
        map<pair<int, int>, set<char>> squares;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.')
                    continue;
                pair<int, int> coord = {r / 3, c / 3};
                char ele = board[r][c];
                if (rows[r].count(ele) || cols[c].count(ele) ||
                    squares[coord].count(ele))
                    return false;
                rows[r].insert(ele);
                cols[c].insert(ele);
                squares[coord].insert(ele);
            }
        }
        return true;
    }
};
```
Tags: [[Arrays]], [[Matrix]], [[Sets]], [[Maps]]