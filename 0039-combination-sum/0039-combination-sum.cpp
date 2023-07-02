class Solution {
public:
    void solve(int i,int sum,vector<int> v,vector<int> a,int tar,vector<vector<int>> &ans){
        if(i==a.size() || sum>=tar){
            if(sum==tar){
                ans.push_back(v);
            
            }
            return;
        }
        
        solve(i+1,sum,v,a,tar,ans);
        sum+=a[i];
        v.push_back(a[i]);
        solve(i,sum,v,a,tar,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int tar) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,0,v,a,tar,ans);
        return ans;
    }
};