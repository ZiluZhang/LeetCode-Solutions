// Insert Interval
// vector.insert(iterator, element)
// vector.erase(iterator)
// max/min在头文件algorithm里
// 因为是按start排好序的，如果新的end比当前start小，那么直接插入，return
// 如果新的start比当前end大，那么下一个
// 如果有重叠，合成一个，删除当前，继续判断第i个
// 因为vector长度在动态变化，有时需要i++有时不需要，所以while条件要注意

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len = intervals.size();
        if(len == 0) return vector<Interval>(1, newInterval);
        int i = 0;
        while(i < intervals.size()) {
            Interval cur = intervals[i];
            if(newInterval.end < cur.start) {
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
            else if(newInterval.start > cur.end) {
                i++;
            }
            else {
                newInterval.start = min(newInterval.start, cur.start);
                newInterval.end = max(newInterval.end, cur.end);
                intervals.erase(intervals.begin() + i);
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};