//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> st1, st2;
public:
    
    void enqueue(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    int dequeue() {
        if(st1.empty()) return -1;
        int ele=st1.top();
        st1.pop();
        return ele;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends