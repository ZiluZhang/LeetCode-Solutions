// Find Median from Data Stream
// 用两个堆，一个最大堆存前一半，一个最小堆存后一半
// 因为priority_queue默认最大堆，所以最小堆存的时候数都用相反数
// 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
        return;
    }
    
    double findMedian() {
        if(small.size() == large.size())
            return (small.top() - large.top()) / 2.0;
        else
            return small.top();
    }
private:
    priority_queue<int> small, large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */