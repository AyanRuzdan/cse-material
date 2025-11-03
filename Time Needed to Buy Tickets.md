```cpp
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        queue<pair<int, int>> qp;
        for (int i = 0; i < tickets.size(); i++)
        {
            qp.push({tickets[i], i});
        }
        int time = 0;
        while (!qp.empty())
        {
            auto [a, b] = qp.front();
            qp.pop();
            a--;
            time++;
            if ((a == 0) && (b == k))
                return time;
            if (a > 0)
                qp.push({a, b});
        }
        return time;
    }
};
```
