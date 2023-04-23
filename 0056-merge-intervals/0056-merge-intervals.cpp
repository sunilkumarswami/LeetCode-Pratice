class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
         if(a.empty()) return ans;
         sort(a.begin(),a.end());
         int last=a[0][1],n=a.size();
         ans.push_back(a[0]);
         for(int i=0;i<n;i++){
             if(last<a[i][0]){
                 ans.push_back(a[i]);
                 last=a[i][1];
             }
             else{
                 last=max(a[i][1],ans.back()[1]);
                 ans.back()[1]=last;
             }
         }
         
        return ans;
    }
};