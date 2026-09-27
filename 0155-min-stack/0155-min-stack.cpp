class MinStack {
public:
    vector<int>stack;
    int tops = -1;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        tops++;
        stack.push_back(value);
        if(value<mini)
        mini=value;
    }
    
    void pop() {
        if(stack[tops]==mini){
            int x = INT_MAX;
            for(int i=0;i<tops;i++){
                if(x>stack[i])
                x=stack[i];
            }
            mini = x;
        }
        stack.pop_back();
        tops--;
        if(tops==-1)
        mini = INT_MAX;
    }
    
    int top() {
        return stack[tops];
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */