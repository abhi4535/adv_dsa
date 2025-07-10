#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int f(vector<int> &height, int i,int k){
    if(i==height.size()-1)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=INT_MAX;
    for(int j=1; j<=k; j++){
        if(i+j<height.size())ans=min(abs(height[i]-height[i+j])+f(height,i+j,k),ans);
        else break;
    }
    return dp[i]= ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> height(n);
    for(int i=0; i<n; i++){
        cin>>height[i];
    }
    dp.resize(n+2,-1);
    cout<<f(height,0,k);
}