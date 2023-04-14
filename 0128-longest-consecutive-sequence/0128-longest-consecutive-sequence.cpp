class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
        sort(a.begin(),a.end());
        int cnt=1,maxi=1;
        for(int i=1;i<n;i++){
            if((a[i]-a[i-1])==1) cnt++;
            else if((a[i]-a[i-1])==0);
            else{
                maxi=max(cnt,maxi);
                cnt=1;
            }
        }
        maxi=max(cnt,maxi);
        return maxi;
    }
};