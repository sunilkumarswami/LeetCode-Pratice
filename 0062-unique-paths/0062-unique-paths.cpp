class Solution {
public:
    int uniquePaths(int a, int b) {
        vector<vector<int>> dp(a,vector<int>(b,0));
        vector<int> past(b,1),cur(b,0);
        
        for(int i=1;i<a;i++){
            for(int j=0;j<b;j++){
                cur[j]=past[j];
                if(j>0) cur[j] += cur[j-1];
            }
            past=cur;
        }
        return past[b-1];
    }
};