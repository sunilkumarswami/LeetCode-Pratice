class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q1.size();
        q1.push(x);
        while(size--){
            int num=q1.front();
            q1.pop();
            q1.push(num);
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int top=q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        if(q1.empty()) return -1;
        int top=q1.front();
        return top;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */