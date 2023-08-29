#include<bits/stdc++.h>
using namespace std;


/*
    5 8
    ########
    #.A#...#
    #.##.#B#
    #......#
    ########


    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<maiz[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
*/
typedef pair<int,int>intpr;
const int N=2002;

int maiz[N][N], visited[N][N], level[N][N];
pair<int,int>src,dst;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n,m;

bool is_inside(intpr coord){
    int x=coord.first;
    int y=coord.second;
    if(x>=0 and x<n and y>=0 and y<m)return true;
    return false;
}
bool is_forbidden(intpr coord){
    int x=coord.first;
    int y=coord.second;
    if(maiz[x][y]==-1)return true;
    return false;
}

void bfs(intpr src){
    queue<intpr>q;
    visited[src.first][src.second]=1;
    level[src.first][src.second]=0;
    q.push(src);
    while(!q.empty()){
        intpr head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;
        for(int i=0; i<4; i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            intpr adj_node={new_x,new_y};
            if(is_inside(adj_node) and
                !is_forbidden(adj_node) and
                visited[new_x][new_y]!=1){

                visited[new_x][new_y]=1;
                level[new_x][new_y]=level[x][y]+1;
                q.push(adj_node);
            }
        }
    }
}

int main(){
     cin>>n>>m;

     for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            maiz[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            level[i][j]=-1;
        }
    }

    for(int i=0; i<n; i++){
        string inp; cin>>inp;
        for(int j=0; j<m; j++){
            if(inp[j]=='#'){
                maiz[i][j]=-1;
            }
            else if(inp[j]=='A'){
                src={i,j};
            }
            else if(inp[j]=='B'){
                dst={i,j};
            }
        }
    }

    bfs(src);
    if(level[dst.first][dst.second]==-1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n"<<level[dst.first][dst.second]<<endl;
    }


    return 0;
}

