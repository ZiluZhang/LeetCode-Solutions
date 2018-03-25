class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        vector<int> m;
        for(int i = 0; i < len; i++)
        {
            int len2 = m.size();
            int j = 0;
            while(j < len2 && m[j] > nums[i])
                j++;
            if(j < len2 && m[j] < nums[i])
                m.insert(m.begin()+j, nums[i]);
            else if(j == len2)
                m.push_back(nums[i]);
            if(m.size() > 3)
                m.pop_back();
        }
        if(m.size() < 3)
            return m[0];
        return m[m.size()-1];
    }
};