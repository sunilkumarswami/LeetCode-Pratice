class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        if(n==1){
            return ans;
        }
        v.push_back(1);
        ans.push_back(v);
        if(n==2){
            return ans;
        }
        for(int i=3;i<=n;i++){
            vector<int> v;
            v.push_back(1);
            
            for(int j=0;j<ans.back().size()-1;j++){
                v.push_back((ans.back()[j]+ans.back()[j+1]));
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};