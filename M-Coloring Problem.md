```cpp
bool isSafe(int node, int c, vector<int> &color, vector<vector<int>> &adj)
{
    for (auto nghbr : adj[node])
    {
        if (color[nghbr] == c)
            return false;
    }
    return true;
}
bool solve(int node, int m, int v, vector<int> &color, vector<vector<int>> &adj)
{
    if (node == v)
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, i, color, adj))
        {
            color[node] = i;
            if (solve(node + 1, m, v, color, adj))
                return true;
            color[node] = -1;
        }
    }
    return false;
}
bool graphColoring(int v, vector<vector<int>> &edges, int m)
{
    vector<vector<int>> adj(v);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> color(v, -1);
    return solve(0, m, v, color, adj);
}
```