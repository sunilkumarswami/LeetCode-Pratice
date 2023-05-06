class Solution {
public:
    string largestOddNumber(string s) {
        int j=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]%2!=0){
                j=i;
                break;
            }
        }
        return s.substr(0,j+1);
    }
};