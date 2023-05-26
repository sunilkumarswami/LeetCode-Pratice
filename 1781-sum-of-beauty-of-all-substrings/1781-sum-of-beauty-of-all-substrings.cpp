class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            map<char,int> mp;
            multiset<int> st;
            for(int j=i;j<n;j++){
                if(mp.find(s[j])!=mp.end())
                st.erase(st.find(mp[s[j]]));
                mp[s[j]]++;
                st.insert(mp[s[j]]);
                ans+=*st.rbegin()-*st.begin();
            }
        }
        return ans;
    }
};