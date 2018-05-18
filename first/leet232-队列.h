class MyQueue {
public:
    stack<int> data;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> rev;
        while(!data.empty())
        {
            rev.push(data.top());
            data.pop();
        }
        int ret=rev.top();
        rev.pop();
        while(!rev.empty())
        {
            data.push(rev.top());
            rev.pop();
        }
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> rev;
        stack<int> tmp(data);
        while(!tmp.empty())
        {
            rev.push(tmp.top());
            tmp.pop();
        }
        return rev.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
