#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int dp[22][1<<22];
int f(vector<vector<int>> &c,int i,int mask){
    if(i==c.size()){
        if(mask==0)return 1;
        return 0;
    }
    if(dp[i][mask]!=-1)return dp[i][mask];
    int ans=0;
    for(int j=1; j<=c.size(); j++){
        bool womenAvailable=(mask &(1<<(j-1)));
        if(c[i][j] && womenAvailable){
            ans=((ans%mod)+f(c,i+1,mask ^ (1<<(j-1)))%mod)%mod;
        }
    }
    return dp[i][mask]= ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>c(n+1,vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>c[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(c,1,(1<<n)-1);
    return 0;
}
