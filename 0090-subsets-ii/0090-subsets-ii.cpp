class Solution {
public:
    void solve(int ind,vector<int> &v,vector<int> &a,vector<vector<int>> &ans){
        ans.push_back(v);
        if(ind==a.size()) {
            return;}
        
        for(int i=ind;i<a.size();i++){
            if(i>ind && a[i]==a[i-1]) continue;
            v.push_back(a[i]);
            solve(i+1,v,a,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,v,a,ans);
        return ans;
    }
};