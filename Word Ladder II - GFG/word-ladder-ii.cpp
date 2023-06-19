//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string start, string tar, vector<string>& wl) {
        vector<vector<string>> ans;
        set<string> st,curlevel;
        st.insert(start);
        curlevel.insert(start);
        for(int i=0;i<wl.size();i++){
            st.insert(wl[i]);
        }
        queue<vector<string>> q;
        vector<string> v;
        v.push_back(start);
        q.push({start});
        st.erase(start);
        while(!q.empty()){
            if(curlevel.size()>0){
                for(auto it:curlevel){
                    st.erase(it);
                }
            }
            curlevel.clear();
            int size=q.size();
            bool flag=false;
            while(size--){
                vector<string> v=q.front();
                string s=v.back();
            q.pop();
            if(s==tar) {
                ans.push_back(v);
                flag=true;
            }
            else{
                string s2=s;
            for(int i=0;i<s.size();i++){
                
                for(char ch='a';ch<='z';ch++){
                    if(ch!=s[i]){
                        s2[i]=ch;
                        if(st.find(s2)!=st.end()){
                            v.push_back(s2);
                            curlevel.insert(s2);
                            q.push(v);
                            v.pop_back();
                        }
                    }
                }
                s2=s;
              }
             }
            }
            if(flag) return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends