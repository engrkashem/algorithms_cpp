#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;
vector<int> adj_list[N];
int visited[N]={0};
int level[N]={0};


void bfs(){
    int k; cin>>k;
    queue<int>q;
    for(int i=0; i<k; i++){
        int src; cin>>src;
        visited[src]=1;
        q.push(src);
        level[src]=0;
    }

    while(!q.empty()){
        int head=q.front();
        q.pop();
        for(int adj_node:adj_list[head]){
            if(visited[adj_node]==0){
                q.push(adj_node);
                visited[adj_node]=1;
                level[adj_node]=level[head]+1;
            }
        }
    }
}

int main(){
    int nodes,edges; cin>>nodes>>edges;
    for(int i=0; i<edges; i++){
        int u,v; cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs();

    int highest=-1,nd=nodes;
    for(int i=1; i<=nodes; i++){
        if(level[i]>highest){
            highest=level[i];
            nd=i;
        }
        //if(level[i]==highest)nd=min(nd,i);
    }
    cout<<highest<<endl;
    cout<<nd<<"\n";


    return 0;
}
