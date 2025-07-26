#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>>dp;
long long f(vector<int> &val,vector<int> &wei,int i,int w){
    if(i>=val.size())return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    long long res=f(val,wei,i+1,w);
    if(w-wei[i]>=0) res=max(res,val[i]+f(val,wei,i+1,w-wei[i]));
    return dp[i][w]= res;
}

int main(){
    int n,w;
    cin>>n>>w;
    vector<int>val(n),wei(n);
    for(int i=0; i<n; i++){
        cin>>wei[i]>>val[i];
    }
    dp.resize(n+2,vector<long long>(w+3,-1));
    cout<<f(val,wei,0,w);
    return 0;
}