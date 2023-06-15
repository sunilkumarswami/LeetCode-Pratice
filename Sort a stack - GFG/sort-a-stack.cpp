//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void solve(int i,stack<int> &st){
    vector<int> v;
    int j=i;
    while(!st.empty() && j--){
        v.insert(v.begin(),st.top());
        st.pop();
    }
    if(st.empty()) {
        for(int i=0;i<v.size();i++)
        st.push(v[i]);
        return;}

    int val=st.top();
    st.pop();
    j=0;
    for(;j<v.size();j++){
        if(v[j]>val)
        break;
    }
    if(j==v.size()) v.push_back(val);
    else{
        v.push_back(0);
        int k=v.size()-1;
        while(k-1>=0 && k!=j){
            v[k]=v[k-1];
            k--;
        }
        v[j]=val;
    }
    
    for(int i=0;i<v.size();i++)
    st.push(v[i]);
    solve(i+1,st);
}
void SortedStack :: sort()
{
   solve(1,s);
}