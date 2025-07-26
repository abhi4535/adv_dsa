#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n==1 || n==2)return n;
    return f(n-1)+(n-1)*f(n-2);
}

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


int main(){
    file_i_o();
    int n;
    cin>>n;
    cout<<f(n);
}