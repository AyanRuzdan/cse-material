## Code
### Recursive DFS
```cpp
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int i, int j, int color, int orig)
    {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
            image[i][j] == color || image[i][j] != orig)
        {
            return;
        }
        image[i][j] = color;
        dfs(image, i + 1, j, color, orig);
        dfs(image, i, j + 1, color, orig);
        dfs(image, i - 1, j, color, orig);
        dfs(image, i, j - 1, color, orig);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
```
### Iterative BFS
```cpp
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int orig = image[sr][sc];
        if (orig == color)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int rows = image.size(), cols = image[0].size();
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            if (r < 0 || c < 0 || r >= rows || c >= cols || image[r][c] != orig)
                continue;
            image[r][c] = color;
            for (auto [dr, dc] : directions)
            {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols &&
                    image[nr][nc] == orig)
                {
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};
```