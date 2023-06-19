//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string start, string tar, vector<string>& wl) {
        set<string> st;
        st.insert(start);
        for(int i=0;i<wl.size();i++){
            st.insert(wl[i]);
        }
        queue<pair<string,int>> q;
        q.push({start,1});
        st.erase(start);
        while(!q.empty()){
            string s=q.front().first;
            int level=q.front().second;
            q.pop();
            if(s==tar) return level;
            string s2=s;
            for(int i=0;i<s.size();i++){
                
                for(char ch='a';ch<='z';ch++){
                    if(ch!=s[i]){
                        s2[i]=ch;
                        if(st.find(s2)!=st.end()){
                            st.erase(s2);
                            q.push({s2,level+1});
                        }
                    }
                }
                s2=s;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends