class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        map<int, int> cnt;
        vector<int> sect;
        for(int i = 0 ; i < len1; i++)
        {
            if(cnt.find(nums1[i]) == cnt.end())
                cnt.insert(pair<int, int>(nums1[i], 1));
            else
                cnt[nums1[i]]++;
        }
        for(int i = 0 ; i < len2; i++)
        {
            if(cnt.find(nums2[i]) != cnt.end() && cnt[nums2[i]] >= 1)
            {
                cnt[nums2[i]]--;
                sect.push_back(nums2[i]);
            }
        }
        return sect;
    }
};