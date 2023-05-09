class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto x:s) mp[x]++;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        
        while(!pq.empty()){
            auto x=pq.top();
            ans.append(x.first,x.second);
            pq.pop();
        }
        return ans;
    }
};