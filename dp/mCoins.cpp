#include<bits/stdc++.h>
using namespace std; 

vector<int>dp;

int f(int n,int k,int l){

    if(n==1 || n==k || n==l)return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]= !(f(n-1,k,l) && (n-k>0 ? f(n-k,k,l) : true) && (n-l>0 ? f(n-l,k,l): true));
}

int main(){
    int k,l,m;
    cin>>k>>l>>m;
    vector<int>coins(m);
    for(int i=0; i<m; i++)cin>>coins[i];
    string ans="";
    for(int i=0; i<m; i++){
        dp.resize(coins[i]+2,-1);
        if(f(coins[i],k,l))ans+='A';
        else ans+='B';
    }
    cout<<ans;
    return 0;
}