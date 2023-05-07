class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size(),divi=(n+m)/2;
        if(m<n) return findMedianSortedArrays(b,a);
        // if(n==1) return a[0];
        // if(m==0 && n%2!=0) return a[n/2];
        int l=0,h=n;
        while(l<=h){
            int c1=(l+h)/2,c2=(n+m+1)/2-c1;
            int l1=INT_MIN,l2=INT_MIN,h1=INT_MAX,h2=INT_MAX;
            
            if(c1-1>=0 && c1-1<n) l1=a[c1-1];
            if(c1>=0 && c1<n) h1=a[c1];
            if(c2-1>=0 && c2-1<m) l2=b[c2-1];
            if(c2>=0 && c2<m) h2=b[c2];
            
            if(l1<=h2 && l2<=h1){
                double ans;
                if((n+m)%2!=0) return max(l1,l2);
                else{
                    return ((double)max(l1,l2)+(double)min(h1,h2))/2.0;
                }
            }
            else if(l1>h2) h=c1-1;
            else l=c1+1;
        }
        return 0;
    }
};