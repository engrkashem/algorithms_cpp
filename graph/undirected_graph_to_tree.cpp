#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

vector<int>adj_list[N];
int visited[N];

void bfs(int src){
    queue<int>q;
    visited[src]=1;
    q.push(src);

    while(!q.empty()){
        int head=q.front();
        q.pop();


        for(int adj_node:adj_list[head]){
            if(visited[adj_node]==0){
                cout<<head<<" "<<adj_node<<"\n";
                visited[adj_node]=1;
                q.push(adj_node);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;


    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src=1;
    bfs(src);


    return 0;
}
