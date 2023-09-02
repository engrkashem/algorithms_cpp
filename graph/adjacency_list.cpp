#include<bits/stdc++.h>

using namespace std;
/*
    Graph Representation
    =====================
    Topic: Adjacency List/C++ vector

    0 ------- 1
             /  \
           2 --- 3
    # Total Nodes = 4
    # Total Edge = 4
    # Undirected + Unweighted

    0 -> 1
    1 -> 0,2,3
    2 -> 1,3
    3 -> 1,2
*/

int main(){
    int nodes=4;
    vector<int>adj_list[nodes];
    //adj_list[0]={1};
    adj_list[1]={0,2,3};
    adj_list[2]={1,3};
    adj_list[3]={1,2};

    for(int i=0; i<nodes; i++){
        cout<<i<<" -> ";
        for(int j=0; j<adj_list[i].size(); j++){
            cout<<adj_list[i][j];
        }
        cout<<endl;
    }

    return 0;
}
