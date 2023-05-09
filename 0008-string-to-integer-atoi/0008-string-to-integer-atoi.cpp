class Solution {
public:
    int myAtoi(string s) {
        long long ans=0,temp=0;
        int i=0,n=s.size(),neg=0;
        while(i<n && s[i]==' ') i++;
        if(i<n && s[i]=='-'){
            neg=1;
            i++;
        }
        else if(i<n && s[i]=='+'){
            i++;
        }
        while(i<n && (s[i]-'0')>=0 && (s[i]-'0')<=9){
            ans=ans*10+s[i]-'0';
            temp=ans;
            if(neg==1){
                temp=-temp;
                if(temp<INT_MIN) return INT_MIN;
            }
            else if(neg==0){
                if(temp>INT_MAX) return INT_MAX;
            }
            i++;
        }
        if(neg==0){
            if(ans>INT_MAX) ans=INT_MAX;
        }
        else{
            ans=-ans;
            if(ans<INT_MIN) ans=INT_MIN;
            
        }
        return ans;
    }
};