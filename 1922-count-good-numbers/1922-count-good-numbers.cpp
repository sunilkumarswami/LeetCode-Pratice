
class Solution {
public:
    long long mod=1000000007;
    long long solve(long long x,long long n){
        if(n==0) return 1;
        if(n%2==0){
            return solve((x*x)%mod,n/2)%mod;
        }
        else {
            return (x*solve(x,n-1))%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long ans=1;
        
        ans=solve(5,(n+1)/2);
        ans*=solve(4,n/2);
        ans%=mod;
        return ans;
    }
};