#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> adj_list[N];

int main(){
    int n,m; cin>>n>>m;

    for(int i=0; i<m; i++){
        int a; cin>>a;
        if(a==1){
            int u,v; cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        else if(a==2){
            int node; cin>>node;
            for(auto adj_node:adj_list[node]){
                if(adj_node)cout<<adj_node<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
