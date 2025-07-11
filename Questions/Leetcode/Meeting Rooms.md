## Question Statement
Given an array of meeting time interval objects consisting of start and end times `[[start_1,end_1],[start_2,end_2],...] (start_i < end_i)`, determine if a person could add all meetings to their schedule without any conflicts.
## Examples
>Example 1:
>Input: intervals = [(0,30),(5,10),(15,20)]
>Output: false
>Explanation:
> `(0,30)` and `(5,10)` will conflict
>`(0,30)` and `(15,20)` will conflict

>Example 2:
>Input: intervals = [(5,8),(9,15)]
>Output: true
>**Note:**
>(0,8),(8,10) is not considered a conflict at 8
## Approach
The approach here lies the same as the one we use for [[Merge Intervals]], where the intervals are initially sorted and then the start and end timings of adjacent intervals are compared. Here the question demands if the final intervals after merging will be the same in count as initial intervals, i.e. we wish to know if all available intervals are non-conflicting. Using extra space we can make a new list of intervals containing all intervals after merge, as it is given that we only need a bool resultant, this approach is not optimal in terms of space. Once the intervals are sorted, we can iterate over the intervals, and compare the front of the incoming interval with the interval already present at the top/back of the resultant list. Finally we return if the size of the list of intervals present initially is the same as the number of intervals in the final list.
### With extra space
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
As the return type of this question is a boolean value, we can simply check conflicts using the original interval list without simulating the merging and maintaining a resultant vector. After sorting using a custom comparator we iterate over the original list of intervals and compare adjacent intervals for conflicts, if at any place any conflict is found, i.e. `interval[i-1].end > interval[i].start`, we return a false value. If no conflict is found we finally return true.
Time Complexity: $O(nlogn)$
Space Complexity: $O(n)$, for final resultant vector
### Without using extra space
```cpp
bool canAttendMeetings(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(),[](auto& x, auto& y){return x.start < y.start;});
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i-1].end > intervals[i].start) return false;
        }
        return true;
    }
```
Time Complexity: $O(nlogn)$
Space Complexity: $O(1)$
Tags: [[Custom Comparator]], [[Arrays]], [[Sorting]]