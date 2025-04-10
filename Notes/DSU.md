```cpp
class DSU{
public:
	vector<int> size, parent;
	DSU(int n){
		size.resize();
		parent.resize();
		for(int i = 1; i <= n; i++){
			parent[i] = i;
		}
	}
};
```