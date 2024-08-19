# DFS
Depth First Search (or [[DFS]]) is similar to DFS of tree. But unlike trees, a graph can contain cycles. So in order to prevent that, we need to maintain a visited array. A graph can have more than one DFS traversal.
For example for the given graph, one possible DFS traversal can be
![img](https://media.geeksforgeeks.org/wp-content/uploads/20240809162859/Input_undirected_Graph.webp)
**1 2 0 3 4**
The algorithm starts from a given source and explores all reachable vertices from *a* given source. It is similar to [[Preorder Tree Traversal]], where we visit the root, then recur for its children.

```python
func addEdge(adjList, s, e){
	adj[s].add(e)
	adj[e].add(s)
}
func DFSRecur(adjList, visited, s){
	visited[s] = true
	print(s)
	for each vertex V in adj[s]{
		if V is not visited{
			DFS(adjList, visited, i)
			}
	}
}
func DFS(adjList, s){
	visited = array length set to false
	DFSRecur(adjList, visited, s)
}
```