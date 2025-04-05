## Question Statement

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return _the number of islands_.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

## Examples

Example 1:
>Input: grid = [ ["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"] ]
>Output: 1

Example 2:

>Input: grid = [ ["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
>Output: 3

## Approach

We see that when we encounter an island, no matter how small it is i.e. one cell, we can start searching on it's neighbors to check if their neighbors are islands or not. In the given code, first we check if the grid is valid or not. Matrix DFS is iterative on the upper level. In the entire grid we iterate over every cell and check if it is an island or not, if it is an island cell then we increment the island count and initiate the DFS function with the parameter of the grid and the indices at which the island was found. In the DFS function, first we check for boundary condition and circular check so that we don't get stuck in an island loop. If that situation is encountered, we return. Otherwise we turn the island into a water cell and then call DFS on all four directions. 
### Why do we convert island to water in the recursive function?
In order to prevent getting stuck in a loop, as we do not use a visited set we simply set the visited island cell to a water cell so that we do not touch it in later recursive calls. Also conversion of an island to water is required so that in the for loop, each island cell found satisfies the island count, and we need not find the rest of the island again. So in reality, what we have remaining is just one cell of island from each island, the rest of the island is gone.

## Code

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // return condition/overflow condition
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
```
Time Complexity: $O(n^2)$
Space Complexity: $O(n^2)$
Tags: [[DFS (Matrix)]], [[BFS (Matrix)]]