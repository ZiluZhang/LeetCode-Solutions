class MyCalendar {
public:
    vector<vector<int>> c;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int len = c.size();
        for(int i = 0; i < len; i++)
            if(max(start, c[i][0]) < min(end, c[i][1]))
                return false;
        vector<int> tmp(2,0);
        tmp[0] = start;
        tmp[1] = end;
        c.push_back(tmp);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */