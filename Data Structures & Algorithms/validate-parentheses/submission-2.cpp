class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(st.empty() || (c=='(' || c=='{' || c=='[')){
                st.push(c);
                continue;
            }
            char top = st.top();
            if((top=='(' && c==')') || (top=='{' && c=='}') || (top=='[' && c==']')){
                st.pop();
            }else{
                return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
