#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int> &a,
                   const pair<int,int> &b){
    if(a.first!=b.first)
    return a.first>b.first;
    return a.second<b.second;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a;
	    vector<pair<int,int>> vp;
	    map<int,int>mp;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        a.push_back(x);
	        mp[x]++;
	    }
	    
	    for(auto x:mp){
	        vp.push_back({x.second,x.first});
	    }
	    sort(vp.begin(),vp.end(),compare);
	    for(int i=0;i<vp.size();i++){
	        int m=vp[i].first;
	        while(m>0){
	            cout<<vp[i].second<<" ";
	            m--;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}