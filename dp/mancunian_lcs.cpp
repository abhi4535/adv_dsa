#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005][7];
int f(vector<int> &s,vector<int> &t,int i,int j,int k){
    if(i>=s.size() || j>=t.size() )return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(s[i]==t[j])return dp[i][j][k]= 1+f(s,t,i+1,j+1,k);
    return dp[i][j][k]= max((k-1>=0 ? 1+f(s,t,i+1,j+1,k-1): 0),max(f(s,t,i+1,j,k),f(s,t,i,j+1,k)));
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>fst(n);
    vector<int>scnd(m);
    for(int i=0; i<n; i++){
        cin>>fst[i];
    }
    for(int i=0; i<m; i++){
        cin>>scnd[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(fst,scnd,0,0,k);
    return 0;
}