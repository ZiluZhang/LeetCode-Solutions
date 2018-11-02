// Meeting Rooms II
// 把开始/结束时间分别排序
// 两个指针，都从0开始
// 如果s[i]<e[j]说明要加一个房间，i++
// 否则i++ j++

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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s, e;
        int res = 0;
        int i = 0, j = 0;
        int len = intervals.size();
        for(int k = 0; k < len; k++) {
            s.push_back(intervals[k].start);
            e.push_back(intervals[k].end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        while(i < len && j < len) {
            if(s[i] < e[j]) res++;
            else j++;
            i++;
        }
        return res;
    }
};