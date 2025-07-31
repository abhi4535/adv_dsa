#include<bits/stdc++.h>
using namespace std;

vector<int>par;

int find(int x){
    if(par[x]==x)return x;
    return par[x]= find(par[x]);
}

void Union(vector<int> &rank,int a,int b){
    a=find(a);
    b=find(b);
    if(rank[a]>rank[b]){
        rank[a]++;
        par[b]=a;
    }
    else{
        rank[b]++;
        par[a]=b;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    par.resize(n+1);
    vector<int>rank(n+1,0);
    for(int i=0; i<=n; i++){
        par[i]=i;
    }
    while(m--){
        string str;
        cin>>str;
        if(str=="Unoin"){
            int x,y;
            cin>>x>>y;
            Union(rank,x,y);
        }
        else{
            int x;
            cin>>x;
            cout<<find(x)<<endl;
        }
        
    }
    return 0;
    

}