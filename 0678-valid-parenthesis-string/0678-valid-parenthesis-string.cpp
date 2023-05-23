class Solution {
public:
    bool checkValidString(string s) {
        stack<char> open,star;
        for(int i=0;i<s.size() ;i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else{
                    return false;
                }
            }
        }
        while(!open.empty()){
            if(star.empty() || star.top()<open.top()) return false;
            else {
                open.pop();
                star.pop();
            }
        }
        return true;
    }
};