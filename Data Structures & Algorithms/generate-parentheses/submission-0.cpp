class Solution {
public:
    void backtrack(vector<string>& res, string current, int openCount, int closeCount, int n) {
        if (openCount == n && closeCount == n) {
            res.push_back(current);
            return;
        }

        if (openCount < n) {
            backtrack(res, current + "(", openCount + 1, closeCount, n);
        }
        if (closeCount < openCount) {
            backtrack(res, current + ")", openCount, closeCount + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};
