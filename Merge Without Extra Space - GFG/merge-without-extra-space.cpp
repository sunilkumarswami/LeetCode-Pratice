//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long a[], long long b[], int n, int m) 
        { 
            // code here 
            long long mid=(n+m+1)/2;
            while(mid>0){
                int i=0,j=mid;
                while(i<(n+m) && j<(n+m)){
                    long long n1,n2;
                    if(i<n) n1=a[i];
                    else n1=b[i-n];
                    if(j<n) n2=a[j];
                    else n2=b[j-n];
                    
                    if(n2<=n1){
                        if(i<n) a[i]=n2;
                        else b[i-n]=n2;
                        if(j<n) a[j]=n1;
                        else b[j-n]=n1;
                    }
                    i++;
                    j++;
                }
                if(mid==1) break;
                mid=(mid+1)/2;
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends