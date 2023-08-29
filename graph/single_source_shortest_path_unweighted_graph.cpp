#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int> adj_list[N];
int visited[N]={0};
int level[N]={0};


void bfs(int src){
    queue<int>q;

    visited[src]=1;
    q.push(src);
    level[src]=0;

    while(!q.empty()){
        int head=q.front();
        q.pop();
        for(int adj_node:adj_list[head]){
            if(visited[adj_node]!=1){
                visited[adj_node]=1;
                level[adj_node]=level[head]+1;
                q.push(adj_node);
            }
        }
    }
}
/*
    0 ------ 1 -------- 2 ------ 3
             |          |
             |          |
             |          |
             4 -------- 5

             6 6

             0 1
             1 2
             1 4
             2 3
             2 5
             4 5
*/
int main(){
    int nodes,edges; cin>>nodes>>edges;
    for(int i=0; i<edges; i++){
        int u,v; cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src=0;
    bfs(src);

    for(int i=0; i<nodes; i++)cout<<"Node: "<<i<<" -> Level: "<<level[i]<<endl;

    return 0;
}
