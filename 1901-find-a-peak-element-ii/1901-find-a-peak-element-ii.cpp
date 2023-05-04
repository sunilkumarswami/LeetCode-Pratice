class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int l=0,h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int maxR=0;
            for(int i=1;i<n;i++){
                if(a[maxR][mid]<a[i][mid])
                    maxR=i;
            }
            bool leftIsBig=mid-1>=0 && (a[maxR][mid-1]>a[maxR][mid]);
            bool rightIsBig=mid+1<m && (a[maxR][mid+1]>a[maxR][mid]);
            
            if(!leftIsBig && !rightIsBig)
                return vector<int> {maxR,mid};
            else if(leftIsBig) h=mid-1;
            else l=mid+1;
        }
        return vector<int> {-1,-1};
    }
};