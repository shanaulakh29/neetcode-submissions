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
        //O(n^2)
        int minValue=st.top();
        stack<int>tmp;
        while(st.size()){
            minValue = min(minValue,st.top());
            tmp.push(st.top());
            st.pop();
        }
        while(!tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
        return minValue;

        // return dupst.top();
    }
};
