#include<bits/stdc++.h>
using namespace std;

vector<list<int>>graph;

void addNode(int x,int y,bool biDir=true){
    graph[x].push_back(y);
    if(biDir){
        graph[y].push_back(x);
    }
}
unordered_set<int>visited;
void dfs(int i){
    visited.insert(i);
    for(auto g: graph[i]){
        if(!visited.count())dfs(g);
    }
}

int main(){
    int e,v;
    cin>>e>>v;
    while(e--){
        int x,y;
        cin>>x>>y;
        addNode(x,y);
    }
    int cc=0;
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            dfs(i);
            cc++;
        }
    }
    cout<<cc;
    return 0;
}