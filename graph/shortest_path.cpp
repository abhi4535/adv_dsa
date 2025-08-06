#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>gr;

void make_gr(int u,int v,int wt){
    gr[u].push_back({v,wt});
    gr[v].push_back({u,wt});
}

int main(){
    int v,e;
    cin>>v>>e;
    gr.resize(v,vector<pair<int,int>>());
    while(e--){
        int u,v,wt;
        cin>>u>>v>>wt;
        make_gr(u,v,wt);
    }
    int src,dest;
    cin>>src>>dest;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    unordered_set<int>vis;
    vector<int>via(v);
    vector<int>dist(v);
    dist[src]=0;
    via[src]=-1;
    pq.push({0,src});
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        if(!vis.count(curr.second)){
            vis.insert(curr.second);
            for(auto nbr: gr[curr.second]){
                if(!vis.count(nbr.first) && nbr.second+curr.first<dist[nbr.first]){
                    pq.push({nbr.second+curr.first,nbr.first});
                    dist[nbr.first]=nbr.second+curr.first;
                    via[nbr.first]=curr.second;
                }
            }
        }
    }
    cout<<dist[dest];
    return 0;

}