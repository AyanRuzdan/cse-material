> Note: If you are on GFG, then this vector pair to adj list is a requirement for graph questions

Given an undirected graph with **V** nodes and **E** **edges**, create and return an [adjacency list](https://www.geeksforgeeks.org/adjacency-list-meaning-definition-in-dsa/) of the graph. **0-based indexing** is followed everywhere.

**Example 1:**

**Input:  
V = 5, E = 7  
edges = \[[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701247/Web/Other/blobid2_1744376584.jpg)  
**Output:** 
\[[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
**Explanation**:
Node 0 is connected to 1 and 4.  
Node 1 is connected to 0,2,3 and 4.  
Node 2 is connected to 1 and 3.  
Node 3 is connected to 1,2 and 4.  
Node 4 is connected to 0,1 and 3.

**Example 2:**

**Input:  
**V = 4, E = 3  
edges = \[[0,3], [0,2], [2,1]]
![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/701247/Web/Other/blobid5_1744376643.jpg)    
**Output:** 
\[[2,3], [2], [0,1], [0]]
**Explanation**:  
Node 0 is connected to 2 and 3.  
Node 1 is only connected to 2.  
Node 2 is connected to 0 and 1.  
Node 3 is only connected to 0.

```cpp
vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
{
    // do see input format of edges and how it converts to adj
    vector<vector<int>> adj(V);
    for (auto item : edges)
    {
        auto [a, b] = item;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto &item : adj)
        sort(item.begin(), item.end());
    return adj;
}
```
Tags: [[Matrix]]