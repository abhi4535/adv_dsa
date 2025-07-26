#include<bits/stdc++.h>
using namespace std;
int dp[105][105][2];
int f(int n,int k,int last){
    if(n==0){
        if(k==0)return 1;
        return 0;
    }
    if(dp[n][k][last]!=-1)return dp[n][k][last];
    if(last)return dp[n][k][last]= (f(n-1,k,0)+(k-1>=0 ? f(n-1,k-1,1) :0));
    return dp[n][k][last]= (f(n-1,k,0)+f(n-1,k,1));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int i,n,k;
        cin>>i>>n>>k;
        memset(dp,-1,sizeof(dp));
        int ans=(f(n-1,k,0)+f(n-1,k,1));
        cout<<i<<" "<<ans<<endl;
    }
    return 0;
}