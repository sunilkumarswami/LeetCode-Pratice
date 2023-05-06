class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int last=n-1,i=n-1,st=0;
        while(i>=0 && s[i]==' ') i--;
        last=i;
        while(st<n && s[st]==' ') st++;
        string ans="";
        for(;i>=0;i--){
            if(i+1<n && s[i]==' ' && s[i+1]!=' '){
                int j;
                if(i==0) j=0;
                else j=i+1;
                
                ans+=s.substr(i+1,last-i);
                if(st!=i+1){
                    ans+=" ";
                }
                if(i-1>=0 && s[i-1]!=' ')
                last=i-1;
                // ans+=st;
            }
            else if(i+1<n && s[i]!=' ' && s[i+1]==' ') last=i;
            
        }
        if(s[0]!=' '){
            ans+=s.substr(0,last+1);
        }
        return ans;
    }
};