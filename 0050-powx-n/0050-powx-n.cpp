class Solution {
public:
    double solve(double x,long long n){
        if(n==0) return 1.0;
        if(n%2==0) return solve(x*x,n/2);
         return x*solve(x,n-1);
        
    }
    double myPow(double x, int n) {
        long long N=abs(n);
        double ans= solve(x,N);
        if(n<0) return 1.0/ans;
        return ans;
    }
};