#include<bits/stdc++.h>
using namespace std;
/*
    4 3 5
    1 2 5
    1 3 9
    2 3 3
    1 2
    2 1
    1 3
    1 4
    3 2


    5
    5
    8
    -1
    3
*/
//typedef pair<int,int>pr;
const int N=1e3+3;
const long long INF=1e18;
long long d[N][N];
//vector<

int main(){
    int n,m,q;
    cin>>n>>m>>q;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;
        }
    }

    for(int i=0; i<m; i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        d[u][v]=min(d[u][v], w);
        d[v][u]=min(d[v][u], w);
    }

    for(int k=1; k<=n; k++ ){
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                d[u][v]=min(d[u][v], d[u][k]+d[k][v]);
            }
        }
    }

    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        if(d[a][b]!=INF)cout<<d[a][b]<<"\n";
        else cout<<"-1\n";
    }

    return 0;
}

