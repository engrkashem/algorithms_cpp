#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>intpr;
const int N=1e5+5;
const int INF=1e9;
vector<intpr>adj_list[N];
int n,m;
int d[N];

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        d[i]=INF;
    }
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
    }

    int src=1;
    d[src]=0;

    for(int i=1; i<=n-1; i++){//iteration to update all distance (max n-1)
        for(int node=1; node<=n; node++){//selecting all node to explore
            for(intpr adj_node:adj_list[node]){//exploring all adjacent node
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;

                if(d[u]+w<d[v]){
                    d[v]=d[u]+w;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)cout<<d[i]<<" ";.
    cout<<"\n";

    return 0;
}
