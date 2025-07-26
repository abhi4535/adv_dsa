#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> dp;

int f(vector<int> &coins, int tar) {
    if (tar < 0) return INF;
    if (tar == 0) return 0;
    if (dp[tar] != -1) return dp[tar];

    int ans = INF;
    for (int c : coins) {
        ans = min(ans, 1 + f(coins, tar - c));
    }
    return dp[tar] = ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    dp.assign(x + 1, -1);
    int ans = f(coins, x);
    cout << (ans >= INF ? -1 : ans);
    return 0;
}
