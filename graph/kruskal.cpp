#define ll long long
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
    int wt;
};
vector<int>par;

int find(int x){
    return par[x]=(par[x]==x) ? x: find(par[x]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        par[b]=a;
    }
}

ll kruskal(vector<Edge> &edges,int v){
    sort(edges.begin(),edges.end(),[](Edge a, Edge b){
        return a.wt<b.wt;
    });
    ll ans=0;
    int e=0,i=0;
    while(e<v-1 && i<edges.size()){
        int srcpar=find(edges[i].src);
        int destpar=find(edges[i].dest);
        if(srcpar!=destpar){
            Union(srcpar,destpar);
            ans+=edges[i].wt;
            e++;
        }
        i++;
    }
    return ans;
}


int main(){
    int v,e;
    cin>>v>>e;
    vector<Edge>edges(e);
    for(int i=0; i<e; i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    }
    par.resize(v+1);
    for(int i=0; i<=v; i++){
        par[i]=i;
    }
    cout<<kruskal(edges,v);
    return 0;

}