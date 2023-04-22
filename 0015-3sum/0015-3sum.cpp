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
                    j++,k--;
                    while(j<n && num2==a[j]) j++;
                    while(k>=0 && num3==a[k]) k--;
                }
                else if((a[j]+a[k])>sum){
                    num3=a[k];
                    k--;
                    while(k>=0 && num3==a[k]) k--;
                }
                else{
                    num2=a[j];
                    j++;
                    while(j<n && num2==a[j]) j++;
                }
            }
            num1=a[i];
            i++;
            while(i<n && num1==a[i]) i++;
        }
        return ans;
    }
};