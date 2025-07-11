Given an array of meeting time interval objects consisting of start and end times `[[start_1,end_1],[start_2,end_2],...] (start_i < end_i)`, determine if a person could add all meetings to their schedule without any conflicts.

>Example 1:
>Input: intervals = [(0,30),(5,10),(15,20)]
>Output: false
>Explanation:
- `(0,30)` and `(5,10)` will conflict
- `(0,30)` and `(15,20)` will conflict
**Example 2:**
Input: intervals = [(5,8),(9,15)]
Output: true
**Note:**
- (0,8),(8,10) is not considered a conflict at 8
## With extra space
```cpp
bool canAttendMeetings(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(),[](auto& x, auto& y){return x.start < y.start;});
        for(auto interval:intervals){
            if(res.empty() || res.back().end <= interval.start){
                res.push_back(interval);
            }else{
                res.back().end = max(res.back().end, interval.start);
            }
        }
        return res.size() == intervals.size();
    }
```
## Without using extra space
```cpp

```