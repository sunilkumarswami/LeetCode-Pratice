//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string start, string tar, vector<string>& wl) {
        vector<vector<string>> ans;
        unordered_set<string> st(wl.begin(),wl.end());
        vector<string> curlevel;
        curlevel.push_back(start);
        int level=0,ter=INT_MAX;
        queue<vector<string>> q;
        q.push({start});
        
        while(!q.empty()){
            vector<string> v=q.front();
            string s=v.back();
            q.pop();
            if(v.size()>level){
                level++;
                for(auto it:curlevel){
                    st.erase(it);
                }
            }
          
            if(s==tar) {
                if(ans.size()==0)
                ans.push_back(v);
                else if(ans[0].size()==v.size())
                    ans.push_back(v);
            }
            string s2=s;
            for(int i=0;i<s.size();i++){
                char original=s[i];
                for(char ch='a';ch<='z';ch++){
                        s[i]=ch;
                        if(st.count(s)>0){
                            v.push_back(s);
                            curlevel.push_back(s);
                            q.push(v);
                            v.pop_back();
                        }
                }
                s[i]=original;
              }
            
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