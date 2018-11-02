// Meeting Rooms
// 先按开始时间排序，运算符重载！
// 如果当前区间start小于前一个区间end，就不行

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len <= 1) return true;
        // sort by start time
        sort(intervals.begin(), intervals.end(), 
            // 运算符重载
             [](const Interval &a, const Interval &b){return a.start < b.start;});
        for(int i = 1; i < len; i++) {
            if(intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};