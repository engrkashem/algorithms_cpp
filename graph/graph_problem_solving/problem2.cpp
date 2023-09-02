#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int adj_matrix[n][n]={};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a; cin>>a;
            adj_matrix[i][j]=a;
        }
    }

    bool undirected=true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj_matrix[i][i]!=0 || adj_matrix[i][j] != adj_matrix[j][i]){
                undirected=false;
                break;
            }
        }
    }

    if(undirected)cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}
