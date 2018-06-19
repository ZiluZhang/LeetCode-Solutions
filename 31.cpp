class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        vector<int> tmp(nums);
        sort(tmp.rbegin(), tmp.rend());
        if(tmp == nums)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int i = len-1;
        while(i > 0 && nums[i] <= nums[i-1])
            i--;
        int k = i-1;
        int t = nums[i];
        if(k >= 0)
        {
            for(int j = i+1; j < len; j++)
            {
                if(nums[j] > nums[k] && t > nums[j])
                {
                    t = nums[j];
                    i=j;
                    cout << i << j << endl;
                }
            }
            cout << i << k << endl;
            swap(nums[k], nums[i]);
            sort(nums.begin()+k+1, nums.end());
        }
        return;
    }
    
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
        return;
    }
};

//     void nextPermutation(vector<int>& nums) {
//         vector<int> a(nums);
//         sort(a.rbegin(), a.rend());
//         if(a==nums){
//             sort(nums.begin(),nums.end());
//         }
//         else{
//         int i = nums.size() - 1;
//         while(i>0&&nums[i]<=nums[i-1]){
//             i--;
//         }
//         int k=i-1,t=nums[i];
//         if(k>=0){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[j]>nums[k]&&t>nums[j]){
//                     t=nums[j];
//                     i=j;
//                 }
//             }
//             swap(nums[k],nums[i]);
//             sort(nums.begin() + k+1,nums.end());
//             }
//         }

//     }