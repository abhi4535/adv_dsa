#include<bits/stdc++.h>
using namespace std;
vector<long long> dp;
const int MOD = 1e9+7;
long long f(int n){
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    long long ans=0;
    for(int i=1; i<=6; i++){
        ans = (ans + f(n - i)) % MOD;
    }
    return dp[n]= ans;
}

int main(){
    int n;
    cin>>n;
    dp.resize(n+5,-1);
    cout<<f(n);
}