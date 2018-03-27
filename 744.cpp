class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        vector<char> uniq;
        int i = 0;
        char prev;
        while(i < len)
        {
            uniq.push_back(letters[i]);
            prev = letters[i];
            while(i < len && letters[i] == prev)
                i++;
        }
        len = uniq.size();
        if(uniq[len-1] <= target)
            return uniq[0];
        if(uniq[0] > target)
            return uniq[0];
        int left = 0;
        int right = len-1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(uniq[mid] == target)
                return uniq[mid+1];
            else if(uniq[mid] < target)
                left = mid + 1;
            else if(uniq[mid] > target)
                right = mid;
        }
        return uniq[left];
    }
};