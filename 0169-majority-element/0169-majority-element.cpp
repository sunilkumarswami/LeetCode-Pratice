class Solution {
public:
    int majorityElement(vector<int>& a) {
        int el,cnt=0,n=a.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                el=a[i];
                cnt++;
            }
            else if(el==a[i])
                cnt++;
            else 
                cnt--;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==el) cnt++;
        }
        if(cnt>n/2) return el;
        return -1;
    }
};