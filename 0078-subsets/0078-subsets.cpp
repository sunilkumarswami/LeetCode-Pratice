class Solution {
public:
    void solve(int i,vector<int> v,vector<int> nums,vector<vector<int>> &ans,int n){
	        if(i==n){
	            ans.push_back(v);
	            return;
	        }
	        solve(i+1,v,nums,ans,n);
	        v.push_back(nums[i]);
	        solve(i+1,v,nums,ans,n);
	    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        vector<vector<int>> ans;
        solve(0,v,nums,ans,n);
		return ans;
    }
};