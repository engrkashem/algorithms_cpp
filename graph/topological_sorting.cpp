#include<bits/stdc++.h>
using namespace std;

/*
    5 3
    1 2
    3 1
    4 5


*/
const int N= 2e5+5;

vector<int>adj_list[N];
int visited[N];
stack<int>node_stack;

bool isDAG(int node){
    visited[node]=1;

    for(int adj_node:adj_list[node]){
        //visited[adj_node]==0 -> unexplored node|apply dfs
        if(visited[adj_node]==0){
            bool got_cycle=isDAG(adj_node);
            if(got_cycle)return true;
        }
        //visited[adj_node]==1 -> paused node | cycle detected
        else if(visited[adj_node]==1){
            return true;
        }
        //visited[adj_node]==2 -> done node | continue
    }
    visited[node]=2;
    return false;
}

void dfs(int node){
    visited[node]=1;

    for(int adj_node:adj_list[node]){
        if(visited[adj_node]==0){
            dfs(adj_node);
        }
    }
    node_stack.push(node);
}

int main(){
    int n,m; cin>>n>>m;

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adj_list[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            bool got_cycle=isDAG(i);
            if(got_cycle){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++)visited[i]=0;

    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            dfs(i);
        }
    }

    while(!node_stack.empty()){
        cout<<node_stack.top()<< " ";
        node_stack.pop();
    }
    cout<<"\n";


    return 0;
}

