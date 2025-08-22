## What is BFS?
BFS or Breadth-First Search is a graph traversal algorithm which uses a queue data structure to explore all nodes of a given level before moving onto a deeper or next level.
## Approach
An adjacency list based BFS utilizes the storage of neighbors of a node in a list to iterate over the neighbors and perform a breadth first search for that specific node. Queue data structure ensures that a node picked up from the start of the queue lists out all neighboring nodes and inserts them back to the end of the queue. In order to avoid getting stuck in a loop, a visited boolean array is also to be maintained for each visited node so that no node is visited more than once. As there is a queue data structure used there is no need of a stack or a recursion stack, hence this approach is iterative in nature and not recursive like [[DFS]].
## Code
```cpp
void bfs(vector<vector<int>> &adj, int start, int n)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto neighbour : adj[node])
        {
            if (visited[neighbour] == false)
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
/*
The adjacency list is made in the following manner:
Let u be source node and v be destination node
vector<vector<int>> adj(n+1); to store n nodes starting from 1 to N
adj[u].push_back(v);
adj[v].push)back(u);
As the graph is undirected, we need to add edge from both directions.
*/
```
Time Complexity: $O(V+E)$ since each vertex and edge is processed at most once
Space Complexity: $O(V)$ as queue might contain all vertices at once
Tags: [[BFS]], [[Graphs]], [[Queues]]