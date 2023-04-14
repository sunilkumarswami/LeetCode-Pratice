class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
        set<int> st(a.begin(),a.end());
         
        long long last=INT_MIN+100,cnt=1,maxi=1;
        for(auto x:st){
            if(x-last==1) cnt++;
            else{
                maxi=max(maxi,cnt);
                cnt=1;
            }
            last=x;
        }
        maxi=max(cnt,maxi);
        return maxi;
    }
};