class MyCalendarTwo {
public:
    vector<vector<int>> calendar;
    vector<vector<int>> overlap;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int len1 = overlap.size();
        cout << len1 << endl;
        for(int i = 0; i < len1; i++)
            // if((overlap[i][0] <= start && start < overlap[i][1]) || (overlap[i][0] < end && end <= overlap[i][1]))
            if(max(start, overlap[i][0]) < min(end, overlap[i][1]))
                return false;
        int len2 = calendar.size();
        // cout << len2 << endl;
        for(int i = 0; i < len2; i++)
        {
            // if((calendar[i][0] <= start && start < calendar[i][1]) || (calendar[i][0] < end && end <= calendar[i][1]))
            if(max(start, calendar[i][0]) < min(end, calendar[i][1]))
            {
                vector<int> tmp(2,0);
                tmp[0] = max(start, calendar[i][0]);
                tmp[1] = min(end, calendar[i][1]);
                overlap.push_back(tmp);
            }
        }
        vector<int> t(2,0);
        t[0] = start;
        t[1] = end;
        calendar.push_back(t);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */