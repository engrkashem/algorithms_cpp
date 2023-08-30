/*
input:
    5 3
    1 2
    1 3
    4 5
not bi colorable
    5 4
    1 2
    1 3
    4 5
    2 3

output: 1 2 2 1 2/ 1 2 2 2 1/ 2 1 1 2 1

    1 ------ 2
    |
    |
    3

    4 ------- 5
*/
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int visited[N], color[N];
vector<int>adj_list[N];

bool dfs(int node){
    //cout<<node<<" ";
    visited[node]=1;

    for(int adj_node:adj_list[node]){
        if(visited[adj_node]==0){
            //assign diff color to adj node
            if(color[node]==1)color[adj_node]=2;
            else color[adj_node]=1;
            bool is_biColorable=dfs(adj_node);
            if(!is_biColorable)return false;
        }
        else{
            //check if color is same or different
            if(color[adj_node]==color[node])return false;
        }
    }
    return true;
}

int main(){
    int nodes, edges; cin>>nodes>>edges;
    for(int i=0; i<edges; i++){
        int u,v; cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int is_biColorable=true;
    for(int i=1; i<=nodes; i++){
        if(visited[i]==0){
            color[i]=1;
            bool ok=dfs(i);
            if(!ok){
                is_biColorable=false;
                break;
            }
        }
    }

    if(!is_biColorable)cout<<"IMPOSSIBLE\n";
    else{
        for(int i=1; i<=nodes; i++){
            cout<<color[i]<<" ";
        }
        cout<<"\n";
    }

    //int src=1;
    //dfs(src);

    return 0;
}
