class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& ni) {
        vector<vector<int>> ans;
        int n=a.size();
        if(n==0) {
            ans.push_back(ni);
            return ans;
        }
        
        bool flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                if(a[i][1]<ni[0]){
                    ans.push_back(a[i]);
                }
                else{
                    flag=false;
                    if(ni[1]>=a[i][0])
                    ans.push_back({min(ni[0],a[i][0]),max(ni[1],a[i][1])});
                    else{
                        ans.push_back(ni);
                        ans.push_back(a[i]);
                    }
                }
            }
            else{
                if(a[i][0]<=ans.back()[1]){
                    ans.back()[1]=max(ans.back()[1],a[i][1]);
                }
                else ans.push_back(a[i]);
            }
        }
        if(a[n-1][1]<ni[0]) ans.push_back(ni);
        return ans; 
    }
};