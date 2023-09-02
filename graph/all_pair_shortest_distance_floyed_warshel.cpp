#include<bits/stdc++.h>
using namespace std;

//typedef pair<int,int>pr;
const int N=1e3+3;
const int INF=1e9;
int d[N][N];
int n,m;
//vector<

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)d[i][j]=0;
            else d[i][j]=INF;
        }
    }
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
    }

    //diagonal component made zero previously with assigning INFINITY
    //for(int i=1; i<=n; i++){
        //d[i][i]=0;
    //}

    for(int k=1; k<=n; k++ ){
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                d[u][v]=min(d[u][v], d[u][k]+d[k][v ]);
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
