class MinStack {
    stack<int> s;
    stack<int> ms;
    public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(s.empty() && ms.empty()){
            s.push(x);
            ms.push(x);
        } else if(x <= ms.top()){
            s.push(x);
            ms.push(x);
        } else {
            s.push(x);
        }
    }

    void pop() {
        int val = s.top();
        s.pop();
        if(val == ms.top())
            ms.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop(); 
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
