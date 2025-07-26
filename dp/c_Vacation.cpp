#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(vector<vector<int>> &act, int i, int lastAct){
    if(i == act.size()) return 0;
    if(dp[i][lastAct] != -1) return dp[i][lastAct];
    int res = 0;
    for(int actToday = 0; actToday < 3; ++actToday){
        if(actToday != lastAct)
            res = max(res, act[i][actToday] + f(act, i+1, actToday));
    }
    return dp[i][lastAct] = res;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>act(n,vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>act[i][j];
        }
    }
    dp.resize(n+3,vector<int>(4,-1));
    
    int ans=max(act[0][0]+f(act,1,0),max(act[0][1]+f(act,1,1),act[0][2]+f(act,1,2)));
    cout<<ans;
}