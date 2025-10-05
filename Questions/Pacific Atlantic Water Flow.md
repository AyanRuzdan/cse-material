---
cover: https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg
---

```cpp
void dfs(vector<vector<int>> &heights, int i, int j, vector<vector<bool>> &vis, int prevHeight)
{
    int m = heights.size(), n = heights[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] ||
        heights[i][j] < prevHeight)
        return;
    vis[i][j] = true;
    dfs(heights, i + 1, j, vis, heights[i][j]);
    dfs(heights, i - 1, j, vis, heights[i][j]);
    dfs(heights, i, j + 1, vis, heights[i][j]);
    dfs(heights, i, j - 1, vis, heights[i][j]);
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        dfs(heights, i, 0, pacific, -1);
        dfs(heights, i, n - 1, atlantic, -1);
    }
    for (int j = 0; j < n; j++)
    {
        dfs(heights, 0, j, pacific, -1);
        dfs(heights, m - 1, j, atlantic, -1);
    }
    vector<vector<int>> res;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
                res.push_back({i, j});
        }
    }
    return res;
}
```