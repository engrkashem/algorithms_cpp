#include<bits/stdc++.h>

using namespace std;
/*
    Graph Representation
    =====================
    Topic: Adjacency Matrix

    0 ------- 1
             /  \
           2 --- 3
    # Total Nodes = 4
    # Total Edge = 4
    # Undirected + Unweighted

    matrix  -> #of  nodes X #of nodes
            -> 4X4

    matrix[i][j]=1 if ans only if (i -> j)

    0 -> 1
    1 -> 0
    1 -> 2
    2 -> 1
    2 -> 3
    3 -> 2
    3 -> 1
    1 -> 3


    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            matrix[i][j]=0;
        }
    }
*/

int main(){
    int nodes=4;
    int matrix[nodes][nodes] ={};
    matrix[0][1]=1;
    matrix[1][0]=1;

    matrix[1][2]=1;
    matrix[2][1]=1;

    matrix[2][3]=1;
    matrix[3][2]=1;

    matrix[3][1]=1;
    matrix[1][3]=1;
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
