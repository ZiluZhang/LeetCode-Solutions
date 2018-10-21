// Search a 2D Matrix
// 其实就是二分


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        if(len == 0) return false;
        int wid = matrix[0].size();
        int left = 0, right = len*wid-1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(matrix[mid/wid][mid%wid] == target)
                return true;
            else if(matrix[mid/wid][mid%wid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};