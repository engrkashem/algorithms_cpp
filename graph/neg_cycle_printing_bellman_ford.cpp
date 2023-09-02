#include<bits/stdc++.h>
using namespace std;

typedef pair<int,long long>pr;
const int N=1e5+5;
const long long INF=1e18;
int n,m;
long long d[N];
int parent[N];
vector<pr>adj_list[N];

/*
    4 5
    1 2 1
    2 4 1
    3 1 1
    4 1 -3
    4 3 -2
*/

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        d[i]=INF;
    }
    for(int i=0; i<m; i++){
        int a, b;
        long long c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
    }

    //int src=1;
    //d[1]=0;

    bool is_neg_cycle=false;
    int last_updated_node=-1;
    for(int i=1; i<=n; i++){
        for(int node=1; node<=n; node++){
            for(pr adj_node:adj_list[node]){
                int a=node;
                int b=adj_node.first;
                long long c=adj_node.second;

                if(d[a]+c < d[b]){
                    d[b]=d[a]+c;
                    parent[b]=a;
                    if(i==n){
                        is_neg_cycle=true;
                        last_updated_node=b;
                        break;
                    }
                }
            }
        }
    }

    if(!is_neg_cycle){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    int selected_node=last_updated_node;
    for(int i=1; i<=n-1; i++){
        selected_node=parent[selected_node];
    }
    vector<int>cycle;
    int first_node=selected_node;
    cycle.push_back(selected_node);

    while(true){
        selected_node=parent[selected_node];
        cycle.push_back(selected_node);
        if(selected_node==first_node)break;
    }

    reverse(cycle.begin(),cycle.end());

    for(auto node:cycle)cout<<node<<" ";
    cout<<"\n";


    return 0;
}
