// Merge Intervals
// 参见057 Insert Interval
// 也可以先sort
// 注意sort自定义函数！写在最外面！参数要用const！

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// solution 1
bool mysort(const Interval &a, const Interval &b) {
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len == 0) return {};
        sort(intervals.begin(), intervals.end(), mysort);
        // sort(intervals.begin(), intervals.end(), [](Interval & a, Interval & b) {return a.start < b.start;});
        vector<Interval> res(1, intervals[0]);
        for(int i = 1; i < len; i++) {
            Interval curlast = res.back();
            if(intervals[i].start > curlast.end) {
                res.push_back(intervals[i]);
            }
            else {
                res.back().end = max(curlast.end, intervals[i].end);
            }
        }
        return res;
    }
};


// solution 2
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len == 0) return {};
        vector<Interval> res(1, intervals[0]);
        for(int i = 1; i < len; i++) {
            insert(res, intervals[i]);
        }
        return res;
    }
    
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