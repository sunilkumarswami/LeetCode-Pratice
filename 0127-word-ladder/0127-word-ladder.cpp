class Solution {
public:
    int ladderLength(string start, string tar, vector<string>& wl) {
        map<string,int> mp;
        set<string> st;
        mp[start]=1;
        for(int i=0;i<wl.size();i++){
            mp[wl[i]]=0;
            st.insert(wl[i]);
        }
        queue<pair<string,int>> q;
        q.push({start,1});
        
        while(!q.empty()){
            string s=q.front().first;
            int level=q.front().second;
            q.pop();
            if(s==tar) return level;
            string s2=s;
            for(int i=0;i<s.size();i++){
                
                for(char ch='a';ch<='z';ch++){
                    if(ch!=s[i]){
                        s2[i]=ch;
                        if(st.find(s2)!=st.end() && mp[s2]==0){
                            mp[s2]=1;
                            q.push({s2,level+1});
                        }
                    }
                }
                s2=s;
            }
        }
        return 0;
    }
};