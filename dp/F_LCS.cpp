#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
string ans="";

int f(string &s,string &t,int i, int j,string ds){
    if(ds.size()>ans.size())ans=ds;
   
    if(i>=(int)s.size() || j>=(int)t.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]= 1+f(s,t,i+1,j+1,ds+s[i]);
    return dp[i][j]= max(f(s,t,i+1,j,ds),f(s,t,i,j+1,ds));
}
int main(){
    string s,t;
    cin>>s>>t;
    
    dp.resize(s.size()+2,vector<int>(t.size()+2,-1));
    f(s,t,0,0,"");
    cout<<ans; 
    return 0;
}