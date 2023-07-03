class Solution {
public:
    void solve(int ind,int sum,vector<int> &v,vector<int> &a,vector<vector<int>> &ans){
        
            if(sum==0) {
                ans.push_back(v);
            }
        for(int i=ind;i<a.size();i++){
            if(i>ind && a[i-1]==a[i]) continue;
            
                if(a[i]>sum) break;
                v.push_back(a[i]);
                solve(i+1,sum-a[i],v,a,ans);
                v.pop_back();
        }
        // solve(ind+1,sum,v,a,ans);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        // set<vector<int>> st;
        vector<int> v;
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        solve(0,target,v,a,ans);
        
        // for(auto it:st) ans.push_back(it);
        return ans;
    }
};