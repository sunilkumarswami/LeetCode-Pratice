class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int> mp;
        vector<pair<int,char>> v;
        for(auto x:s) mp[x]++;
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            int m=v[i].first;
            while(m--) ans+=v[i].second;
        }
        return ans;
    }
};