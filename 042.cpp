// Trapping Rain Water



class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int l = 0;
        int r = len - 1;
        int leftmax = 0, rightmax = 0;
        int vol = 0;
        while(l < r)
        {
            if(height[l] < height[r])
            {
                if(height[l] > leftmax)
                    leftmax = height[l];
                else
                    vol += leftmax - height[l];
                l++;
            }
            else
            {
                if(height[r] > rightmax)
                    rightmax = height[r];
                else
                    vol += rightmax - height[r];
                r--;
            }
        }
        return vol;
    }
};