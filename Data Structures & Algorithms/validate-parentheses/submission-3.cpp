class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            //time complexity is O(n) since we are traversing through the entire string and push and pop operations on stack take O(1) time. 
            //space complexity is O(n) as well since in worst case string s can be only of openig brackets like "(((((((" in which case we fill the stack with these opening brackets.
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
