```cpp
class dsu {
public:
    vector<int> size, parent;
    dsu(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
			size[a] += size[b];
        }
    }
};
```