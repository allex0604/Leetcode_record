class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int a = 0, ans = 0, n = s.size();
        for(int i=0; i<n; ++i){
            a = s.top();
            s.pop();
            temp.push(a);
        }
        ans = temp.top();
        temp.pop();
        n = temp.size();
        for(int i=0; i<n; ++i){
            a = temp.top();
            temp.pop();
            s.push(a);
        }
        return ans;
    }
    
    int peek() {
        int a = 0, ans = 0, n = s.size();
        for(int i=0; i<n; ++i){
            a = s.top();
            s.pop();
            temp.push(a);
        }
        ans = temp.top();
        n = temp.size();
        for(int i=0; i<n; ++i){
            a = temp.top();
            temp.pop();
            s.push(a);
        }
        return ans;
    }
    
    bool empty() {
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */