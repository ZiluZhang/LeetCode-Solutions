// Course Schedule III

// 用优先队列，按照课程时间从大到小排
// sort一下课程，按结束时间排序
// 从头开始加课程，如果时间超了，就把堆顶pop
// 因为要去掉一门课，肯定是去掉最长的一门
// priotiry_queue默认最大堆

// 运算符重载还是不会写啊！


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int cur = 0;
        priority_queue<int> p;
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1];});
        for(auto c: courses) {
            cur += c[0];
            p.push(c[0]);
            if(cur > c[1]) {
                cur -= p.top(); p.pop();
            }
        }
        return p.size();
    }
};