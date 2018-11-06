// Two Sum III - Data structure design
// 插入的数可能有重复，用unordered_map记录次数
// 判断target和这个数是否相等，不等，则存在target就行；相等，则需要出现两次才行
// ++nums[number]如果map里本身没有，初始为0，所以可以！


class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        return;
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++nums[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto a: nums) {
            int target = value - a.first;
            if(target != a.first && nums.count(target)) return true;
            if(target == a.first && nums[target] > 1) return true;
        }
        return false;
    }
private:
    unordered_map<int, int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */