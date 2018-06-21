class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int l = 0;
        int r = len-1;
        int mid;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if(citations[mid] >= (len - mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return len - l;
    }
    // int hIndex(vector<int>& citations) {
    //     int left=0, len = citations.size(), right= len-1,  mid;
    //     while(left<=right)
    //     {
    //         mid=left+ (right-left)/2;
    //         if(citations[mid] >= (len-mid)) right = mid - 1;
    //         else left = mid + 1;
    //     }
    //     return len - left;
    // }
};