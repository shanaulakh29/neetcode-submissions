class MinStack {
        stack<int>st;
        stack<int>dupst;
public:
    MinStack() {

    }  
    void push(int val) {
        st.push(val);
        if(dupst.empty()){
            dupst.push(val);
        }else{
            int value = min(val, dupst.top());
            dupst.push(value);
        }
    }
    
    void pop() {
        st.pop();
        dupst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return dupst.top();
    }
};
