DFS on a matrix takes place by traversing through the matrix by accessing each element one by one and moving forward in the grid in some specified direction.
![img](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20210316115521/2417583.jpg)
The approach is to use a stack, and populate it with coordinates. There will also be a function called `isValid` to check if a cell is valid or not (to avoid cycles). Now we need to work upon the stack. While the stack is not empty, we pick a cell, and push it's neighbor into the stack. Also use the `isValid` function to stay in bounds and avoid loops.

```python
directionsRow = [0, 1, 0, -1]
directionsCol = [-1, 0, -1, 0]
ROW = 3
COL = 3 # assuming we are working on a 3x3 grid
func isValid(visited[][COL], row, col)
{
	if(row < 0 || col < 0 || row >= ROWS || col >= COLS)
		return false
	if visited[row][col] is true
		return false
	otherwise
		return true # default return condition specifying that the cell is completely valid
}

func DFS(row, col, grid[][COL], visited[][COL])
{
 stack of pair of integers st
 push in st {row, col}
 while stack is not empty{
 make new pair current as top of stack
 pop from stack
 row = current->first
 col = current->second
 # check for cell validity
 if isValid(visited, row col) is false
	 continue
mark visited[row][col] as true
print(grid[row][col])
# iterate for all 4 directions
for( i: 0 -> 4){
	change in row as adjX = row + directionRow[i]
	change in col as adjY = col + directionCol[i]
	push in stack {adjX, adjY}
}
 }
}
```