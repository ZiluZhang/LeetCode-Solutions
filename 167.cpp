class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i1, i2;
        bool found = false;
        for(i1 = 0; i1 < len; i1++)
        {
            if(found)
                break;
            while(i1 < len-2 && numbers[i1+2] == numbers[i1])
                i1 += 1;
            if(target - numbers[i1] < numbers[i1])
                continue;
            for(i2 = i1+1; i2 < len; i2++)
            {
                if(found)
                    break;
                if(i1 == 13011)
                    cout << i2 << endl;
                while(i2 < len-1 && numbers[i2] == numbers[i2+1])
                    i2 += 1;
                if(i1 == 13011)
                    cout << i2 << endl;
                if(i2 >= len)
                    break;
                if(numbers[i1] + numbers[i2] == target)
                    found = true;
            }
        }
        vector<int> ans = vector<int>(2);
        ans[0] = i1;
        ans[1] = i2;
        return ans;
    }
};