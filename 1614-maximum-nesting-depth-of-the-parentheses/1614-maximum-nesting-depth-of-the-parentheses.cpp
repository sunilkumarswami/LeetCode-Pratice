class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,maxi=0;
        for(auto x:s){
            if(x=='(') cnt++;
            else if(x==')') cnt--;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};