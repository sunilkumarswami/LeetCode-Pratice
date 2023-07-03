class Solution {
public:
    void solve(int ind,int sum,int k,vector<int> &ds,vector<vector<int>> &ans){
        if(sum==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(ds.size()>k) return;
        for(int i=ind;i<9;i++){
            if(i+1<=sum){
                ds.push_back(i+1);
                solve(i+1,sum-i-1,k,ds,ans);
                ds.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
    
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,n,k,ds,ans);
        return ans;
    }
};