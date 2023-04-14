class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
        int cnt=1,maxi=1;
        set<int> st(a.begin(),a.end());
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                x++;
                while(st.find(x)!=st.end()){
                    x++;
                    cnt++;
                }
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
        
        return maxi;
    }
};