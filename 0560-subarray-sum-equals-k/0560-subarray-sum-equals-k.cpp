class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size(),cnt=0;
        long long sum=0;
        map<long long,int> mp;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==k) cnt++;
            if(mp.find(sum-k)!=mp.end())
                cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};