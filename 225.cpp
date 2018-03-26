class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q1.size();
        for(int i = 0; i < n-1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q1.pop();
        for(int i = 0; i < n-1; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        int n = q1.size();
        for(int i = 0; i < n-1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int tmp = q1.front();
        q2.push(tmp);
        q1.pop();
        for(int i = 0; i < n; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */