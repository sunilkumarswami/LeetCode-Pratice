class Solution {
public:
    void solve(int i,string s,int n,bool &neg,bool &flag,long long &ans){
        if(i>=n || (!flag && !('0'<=s[i] && s[i]<='9'))) return;
        
         if(!(s[i]==' ')) flag=false;
        if(s[i]==' ') { 
            solve(i+1,s,n,neg,flag,ans);
                      }
        else if(s[i]=='-'){
            neg=true;
            flag=false;
            solve(i+1,s,n,neg,flag,ans);
        }
        else if(s[i]=='+') solve(i+1,s,n,neg,flag,ans);
        else if('0'<=s[i] && s[i]<='9') {
           
            ans=ans*10+(s[i]-'0');
            if(neg && -ans<INT_MIN)
            { 
                ans= INT_MIN;
                return;
            }
            if(!neg && ans>INT_MAX) {
                ans= INT_MAX;
            return;
            }
            solve(i+1,s,n,neg,flag,ans);
        }
           else
           return;
    }
    
    int myAtoi(string s) {
        long long ans=0,temp=0;
        int i=0,n=s.size();
        bool flag=true,neg=false;
        solve(i,s,n,neg,flag,ans);
        if(neg && ans!=INT_MIN) return -ans;
        return ans;
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