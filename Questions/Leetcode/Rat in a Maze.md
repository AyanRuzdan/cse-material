```cpp
void dfs(vector<vector<int>> &maze, int i, int j, vector<string> &res, string temp)
{
    if (i == (maze.size() - 1) && j == (maze[0].size() - 1))
    {
        res.push_back(temp);
        return;
    }
    if (i < 0 || j < 0 || i == maze.size() || j == maze[0].size() || maze[i][j] == 0)
        return;
    maze[i][j] = 0;
    dfs(maze, i + 1, j, res, temp + 'D');
    dfs(maze, i, j - 1, res, temp + 'L');
    dfs(maze, i, j + 1, res, temp + 'R');
    dfs(maze, i - 1, j, res, temp + 'U');

    maze[i][j] = 1;
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    if (maze[0][0] == 0)
        return {};
    vector<string> res;
    string temp = "";
    dfs(maze, 0, 0, res, temp);
    return res;
}
```