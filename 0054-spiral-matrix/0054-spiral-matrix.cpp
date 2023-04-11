class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> v;
        int top=0,left=0,bot=n-1,ryt=m-1;
        while(left<=ryt && top<=bot){
            for(int j=left;j<=ryt;j++){
                v.push_back(a[top][j]);
            }
            top++;
            for(int i=top;i<=bot;i++){
                v.push_back(a[i][ryt]);
            }
            ryt--;
            if(top<=bot){
                for(int j=ryt;j>=left;j--){
                 v.push_back(a[bot][j]);
                
                }
                bot--;
            }
            
            if(left<=ryt){
            for(int i=bot;i>=top;i--){
                // if(v.size()==n*m) return v;
                v.push_back(a[i][left]);
            }
            left++;
            }
        }
        return v;
    }
};