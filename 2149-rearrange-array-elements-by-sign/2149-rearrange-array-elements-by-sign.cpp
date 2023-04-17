class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n=a.size();
        vector<int> b(n,0);
	    
	    int i=0,j=0;
	    for(int k=0;k<n;k++){
	        if(a[k]>=0){
	            b[2*i]=a[k];
	            i++;
	        }
	        else{
	            
	            b[2*j+1]=a[k];
	            j++;
	        } 
	    }
	    return b;
    }
};