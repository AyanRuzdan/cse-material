```cpp
int minMeetingRooms(vector<Interval> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
         { return a.start < b.start; });
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto &interval : intervals)
    {
        if (!pq.empty() && pq.top() <= interval.start)
            pq.pop();          // meeting has ended
        pq.push(interval.end); // in all cases we need the upper bound
    }
    return pq.size();
}
```