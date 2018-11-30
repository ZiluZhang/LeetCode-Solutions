// Pour Water
// 从K处落下V个水滴，对每一个水滴
// 如果左边最终停下的位置比K处停下位置低，就到左边
// 如果右边.....就到右边
// 否则就在K
// 水滴会改变高度

// 向左向右找局部最小值
// 如果一段高度一样，要回滚，要停在离K最近的位置

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int len = heights.size();
        for(int i = 0; i < V; i++) {
            int l = K, r = K;
            while(l > 0 && heights[l] >= heights[l-1]) l--;
            while(l < K && heights[l] == heights[l+1]) l++;
            while(r < len-1 && heights[r] >= heights[r+1]) r++;
            while(r > K && heights[r] == heights[r-1]) r--;
            if(heights[l] < heights[K]) ++heights[l];
            else ++heights[r];
        }
        return heights;
    }
};


// 稍快一点
// 如果左边已经找到了，就不用做右边了
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int len = heights.size();
        for(int i = 0; i < V; i++) {
            int l = K, r = K;
            while(l > 0 && heights[l] >= heights[l-1]) l--;
            while(l < K && heights[l] == heights[l+1]) l++;
            if(heights[l] < heights[K]) {
                ++heights[l];
                continue;
            }
            while(r < len-1 && heights[r] >= heights[r+1]) r++;
            while(r > K && heights[r] == heights[r-1]) r--;
            ++heights[r];
        }
        return heights;
    }
};