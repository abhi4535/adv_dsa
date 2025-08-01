#include<bits/stdc++.h>
using namespace std;

unordered_set<int>vis;
vector<vector<int>>graph;
bool dfs(int src,int parent){
    vis.insert(src);
    for(int nbr: graph[src]){
        if(vis.count(nbr) && nbr!=parent){
            return true;
        }
       else if(!vis.count(nbr)){
            return dfs(nbr,parent);
       }
    }
    return false;

}

bool bfs(int src){
    queue<int>q;
    unordered_set<int>visited;
    vector<int>parent(v,-1);
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int nbr : graph[curr]){
            if(visited.count(nbr) && parent[curr]!=nbr) return true;
            else if(!visited.count(nbr)){
                q.push(nbr);
                parent[nbr]=curr;
                visited.insert(nbr);
            }
        }
    }
    return false;
}


// now apply above  dfs or bfs logic to every node of the graph
int main(){
    int src,dest;
    cin>>src>>dest;
}