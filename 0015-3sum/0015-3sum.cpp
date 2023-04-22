class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        int n=a.size(),num1,num2,num3;
        sort(a.begin(),a.end());
        for(int i=0;i<n;){
            int j=i+1,k=n-1,sum=-a[i];
            
            while(j<k){
                if((a[j]+a[k])==sum){
                    vector<int> v;
                    v.push_back(a[i]);
                    v.push_back(a[j]);
                    v.push_back(a[k]);
                    // sort(v.begin(),v.end());
                    ans.push_back(v);
                    num2=a[j],num3=a[k];
                    while(j+1<n && a[j+1]==a[j]) j++;
                    while(k-1>=0 && a[k-1]==a[k]) k--;
                    j++,k--;
                }
                else if((a[j]+a[k])>sum) k--;
                else j++;
            }
            while(i+1<n && a[i+1]==a[i]) i++;
            i++;
        }
        return ans;
    }
};