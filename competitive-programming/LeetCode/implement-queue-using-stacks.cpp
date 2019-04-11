class MyQueue {
    stack<int> s1;
    stack<int> s2;
    public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        int val;
        while(!s2.empty()) {
            val = s2.top();
            s2.pop();
            s1.push(val);
        }
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val;
        while(!s1.empty()) {
            val = s1.top();
            s1.pop();
            s2.push(val);
        }

        val = s2.top();
        s2.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        int val;
        while(!s1.empty()) {
            val = s1.top();
            s1.pop();
            s2.push(val);
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
