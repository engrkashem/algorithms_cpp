#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
//const long long INF=1e18;
const long long INF=1e9;
typedef pair<int,int>intpr;

vector<intpr>adj_list[N];
int visited[N], d[N];
int nodes,edges;

void dijkstra(int src){
    for(int i=1; i<=nodes; i++){
        d[i]=INF;
    }
    d[src]=0;

    for(int i=0; i<nodes; i++){
        int selected_node=-1;
        //finding minimum distance node
        for(int j=1; j<=nodes; j++){
            if(visited[j]==1)continue;
            //fselecting minimum distance node
            if(selected_node==-1 || d[selected_node]>d[j]){
                selected_node=j;
            }
        }
        visited[selected_node]=1;
        for(auto adj_entry:adj_list[selected_node]){
            int adj_node=adj_entry.first;
            int edge_cost=adj_entry.second;
            if(d[selected_node]+edge_cost < d[adj_node]){
                d[adj_node]= d[selected_node]+edge_cost;
            }
        }
    }
}


int main(){
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++){
        int u,v,w; cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }

    int src=1;
    dijkstra(src);

    for(int i=1; i<=nodes;i++){
        cout<<d[i]<<" ";
    }
    cout<<"\n";

}
