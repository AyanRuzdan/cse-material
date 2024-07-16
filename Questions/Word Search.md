# Question Statement
Given an `m x n` grid of characters `board` and a string `word`, return `true` _if_ `word` _exists in the grid_.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

# Example 1

 ![img](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

Input: board = [ ["A","B","C","E"], ["S","F","C","S"], ["A","D","E","E"] ], word = "ABCCED"
Output: true

# Approach

To solve the problem using a standard Depth-First Search (DFS) approach, start by iterating through each cell in the grid to find a starting point. For each cell, check if it matches the first letter of the word. If a match is found, initiate a DFS to search for the entire word starting from this cell. During the DFS, explore all four possible directions (up, down, left, right) by adjusting the row and column indices. If a cell matches the corresponding letter in the word, mark it as visited by changing its value to a temporary symbol, which prevents revisiting the same cell within the current path.

Continue the search recursively from the neighboring cells. If at any point the word is completely matched, return `true`. After exploring all possible directions from a cell, restore its original value to allow for other potential paths. If no valid path is found after exploring all cells in the grid, return `false`.

# Code

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # size of rows and columns
        rows, cols = len(board), len(board[0])
        # set containing valid coordinates
        path = set()

        # recursive function to find the next letter
        def dfs(r, c, i):
            # index is at the last letter, word is found
            if i == len(word):
                return True
            # coordinates are out of bounds or already existing
            if (
                r < 0
                or c < 0
                or r >= rows
                or c >= cols
                or word[i] != board[r][c]
                or (r, c) in path
            ):
                return False
            # if coords are valid, then add to the path set
            path.add((r, c))
            # check if it is safe to move up or down or left or right
            res = (
                dfs(r + 1, c, i + 1)
                or dfs(r - 1, c, i + 1)
                or dfs(r, c + 1, i + 1)
                or dfs(r, c - 1, i + 1)
            )
            # if moved on, then remove the coordinates so that we don't circle back
            path.remove((r, c))
            # return ans
            return res

        # iterate over every letter in the board to find a starting point
        for r in range(rows):
            for c in range(cols):
                if dfs(r, c, 0):
                    return True
        return False
```

# Time Complexity
Length of row \* length of column \* 4<sup>length of word</sup> \
*O(m\*n\*4<sup>k</sup>)*