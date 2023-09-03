#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int parent[N];

int main(){
    int nodes; cin>>nodes;
    for(int i=1; i<=nodes; i++){
        cin>>parent[i];
    }
    int queries; cin>>queries;
    for(int i=0; i<queries; i++){
        int prnt, chld; cin>>prnt>>chld;
        if(parent[chld]==0 || prnt==chld){
            cout<<"0\n";
            continue;
        }

        int selected_node=chld;
        while(1){
            if(selected_node==prnt){
                cout<<"1\n";
                break;
            }
            if(parent[selected_node]==0){
                cout<<"0\n";
                break;
            }
            selected_node=parent[selected_node];
        }
    }

    return 0;
}

