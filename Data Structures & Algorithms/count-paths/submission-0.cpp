class Solution {
public:
    bool inBounds(int &stepRight, int & stepDown, int& m, int &n){
        if(stepRight<n && stepDown <m){
            return true;
        }
        return false;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>graph(m, vector<int>(n));
        graph[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 || j==n-1){
                    graph[i][j]=1;
                }else{
                    graph[i][j]=graph[i+1][j]+graph[i][j+1];
                }
            }
        }
        return graph[0][0];

    }   
};
