#include<bits/stdc++.h>
using namespace std;
vector<int>par;
vector<int>nodeWt;



vector<vector<pair<int,int>>>graph;
void make(int src,int dest,int wt){
    graph[src].push_back({dest,wt});
    graph[dest].push_back({src,wt});
}


int main(){
    int n,e;
    cin>>n>>e;
    graph.resize(n+1,vector<pair<int,int>>());
    
    while(e--){
        int u,v,wt;
        cin>>u>>v>>wt;
        make(u,v,wt);
    }
    int st;
    cin>>st;
    nodeWt.resize(n+1,INT_MAX);
    par.resize(n+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    unordered_set<int>vis;
    nodeWt[st]=-1;
    par[st]=-1;
    pq.push({-1,st});
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        if(!vis.count(curr.second)){
            vis.insert(curr.second);
            nodeWt[curr.second]=curr.first;
            for(auto nbr : graph[curr.second]){
                if(!vis.count(nbr.first) && nodeWt[nbr.first]>nbr.second && par[curr.second]!=nbr.first){
                        pq.push({nbr.second,nbr.first});
                        nodeWt[nbr.first]=nbr.second;
                        
                        par[nbr.first]=curr.second;
                    
                }
            }
        }

    }
    int ans=0;
    for(int i=0; i<nodeWt.size(); i++){
        if(nodeWt[i]!=INT_MAX)ans+=nodeWt[i];
    }
    cout<<ans+1;
    


    return 0;

}