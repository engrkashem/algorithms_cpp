#include<bits/stdc++.h>
using namespace std;
/*
5 8
########
#..#...#
####.#.#
#..#...#
########
*/

const int N=2002;
typedef pair<int,int>intpr;

int maze[N][N], visited[N][N];
int n,m;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool is_inside(int x, int y){
    if(x>=0 and x<n and y>=0 and y<m)return true;
    return false;
}

void bfs(intpr src){
    queue<intpr>q;
    visited[src.first][src.second]=1;
    q.push(src);

    while(!q.empty()){
        intpr head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;
        for(int i=0; i<4; i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            intpr adj_node={newX,newY};
            if(is_inside(newX, newY) and
                maze[newX][newY]!=-1 and
                visited[newX][newY]==0){
                    visited[newX][newY]=1;
                    q.push(adj_node);
                }
        }
    }

}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string inp; cin>>inp;
        for(int j=0; j<m; j++){
            if(inp[j]=='#'){
                maze[i][j]=-1;
            }
        }
    }
    int room_cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]==0 and maze[i][j]==0){
                intpr src={i,j};
                room_cnt++;
                bfs(src);
            }
        }
    }
    //intpr unvisited_pos={0,0};
    //while (true){
        //unvisited_pos=find_unvisited(unvisited_pos);
        //cout<<unvisited_pos.first<<" "<<unvisited_pos.second<<endl;
        //if (unvisited_pos==pair<int,int>(-1,-1)){
            //break;
        //}
        //bfs(unvisited_pos);
        //room_cnt++;
    //}
    cout<<room_cnt<<endl;

    //for(int i=0; i<n; i++){
        //for(int j=0; j<m; j++){
            //cout<<maze[i][j]<<"\t";
        //}
        //cout<<endl;
    //}
    //cout<<endl;

    //bfs(src);

    return 0;
}
