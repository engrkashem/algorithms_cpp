#include<bits/stdc++.h>
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
    int res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j and adj_matrix[i][j] and adj_matrix[j][i])res++;
        }
    }
    cout<<res/2<<endl;

    return 0;
}
