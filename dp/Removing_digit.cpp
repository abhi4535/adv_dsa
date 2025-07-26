#include<bits/stdc++.h>
using namespace std;

char lar(int n){
    char ch='0';
    string s=to_string(n);
    for(int i=0; i<s.size(); i++){
        ch=max(ch,s[i]);
    }
    return ch;
}

int f(int n){
    if(n==0)return 0;
    char ch=lar(n);
    int sub=ch-'0';
    return 1+f(n-sub);
}

int main(){
    int n;
    cin>>n;
    cout<<f(n);
}