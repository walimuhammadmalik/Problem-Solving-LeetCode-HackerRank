class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
        // Constructor initializes the stacks
    }
    
    void push(int val) {
        mainStack.push(val);
        // If minStack is empty or the current value is less than or equal to the current minimum, push it onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        // If the value being popped is the same as the top of minStack, pop from minStack as well
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();  // Return the top element from the main stack
    }
    
    int getMin() {
        return minStack.top();  // The top of minStack is the minimum value
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
