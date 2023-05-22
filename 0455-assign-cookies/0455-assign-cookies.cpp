class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& sz) {
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        int j=sz.size()-1,i=greed.size()-1,ans=0;
        while(i>=0 && j>=0){
            if(greed[i]<=sz[j]){
                ans++;
                i--,j--;
            }
            else
            i--;
        }
        return ans;
    }
};