class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        int five=0,ten=0,n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]==5) five++;
            else if(a[i]==10 && five>0){
                ten++;
                five--;
            }
            else if(a[i]==20 && ten>0 && five>0){
                ten--;
                five--;
            }
            else if(a[i]==20 && five>2){
                five-=3;
            }
            else return false;
        }
        return true;
    }
};