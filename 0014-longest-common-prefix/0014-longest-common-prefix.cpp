class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        int mini=INT_MAX,n=a.size();
        for(int i=0;i<n;i++){
            int m=a[i].size();
            mini=min(mini,m);
        }
        
            for(int j=0;j<mini;j++){
                for(int i=1;i<n;i++){
                if(a[i][j]!=a[0][j]){
                    // if(j==0) return "-1";
                    return a[0].substr(0,j);
                }
            }
        }
       return a[0].substr(0,mini); 
    }
};