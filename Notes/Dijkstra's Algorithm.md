## Approach
In this approach the data structure used has a adjacency list of pairs defining source and destination with weights assigned.
## Code
```cpp
vector<int> dj(int n, vector<vector<pair<int, int>>> &adj, int src)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```
Tags: [[Graphs]]