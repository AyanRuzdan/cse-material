## Question Statement
For a binary tree, find the level with the maximum number of nodes.
## Approach(Recursive)
Use a hashmap to store the vertical depth and with each `y` value store the list of nodes for that corresponding vertical depth. Then iterate through the map keeping track of the depth that contains the largest list i.e. the maximum number of nodes and return respectively. *Some questions might demand the first found level with the maximum nodes, and that might cause an issue. Workaround includes extra space to keep all levels with have the most node and then returning the first level. See code.*
## Code
```cpp

```
