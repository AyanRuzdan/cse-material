```cpp
vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int nxor = 0;
        for (int i = 0; i < n; i++) nxor ^= arr[i];
        for (int i = 1; i <= n; i++) nxor ^= i;
        int set_bit = nxor & -nxor;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] & set_bit) x ^= arr[i];
            else y ^= arr[i];
        }
        for (int i = 1; i <= n; i++) {
            if (i & set_bit) x ^= i;
            else y ^= i;
        }
        int repeating = 0, missing = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                repeating = x;
                missing = y;
                break;
            }
            if (arr[i] == y) {
                repeating = y;
                missing = x;
                break;
            }
        }
        return {repeating, missing};
    }
```