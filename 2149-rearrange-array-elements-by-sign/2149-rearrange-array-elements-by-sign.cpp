class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n=a.size();
        vector<int> b(n,0);
	    int cntPos=0,cntNeg=0;
	    for(int k=0;k<n;k++){
	        if(a[k]>=0) 
	            cntPos++;
	        else 
	            cntNeg++;
	    }
	    int m=min(cntPos,cntNeg);
	    int i=0,j=0;
	    for(int k=0;k<n;k++){
	        if(a[k]>=0){
	            if(i<m){
	                b[2*i]=a[k];
	            }
	            if(i==m) 
	                i=2*i;
	            if(i>=m)
	            b[i]=a[k];
	            i++;
	        }
	        else{
	            if(j<m){
	                b[2*j+1]=a[k];
	            }
	            if(j==m) 
	                j=2*j;
	            if(j>=m)
	            b[j]=a[k];
	            j++;
	        }
	    }
	    return b;
    }
};