#include<bits/stdc++.h>
using namespace std;

const int N=100;
typedef pair<int,int>pr;

char grid[N][N];
int visited[N][N];
pr src,dst, parent[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n;

bool is_inside(int x, int y){
    if(x>=0 and x<n and y>=0 and y<n)return true;
    return false;
}

void bfs(pr src){
    queue<pr>q;
    visited[src.first][src.second]=1;
    q.push(src);

    while(!q.empty()){
        pr head=q.front();
        q.pop();
        auto [x,y]=head;
        //int x=head.first;
        //int y=head.second;

        for(int i=0; i<4; i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            pr adj_node={newX,newY};

            if(is_inside(newX,newY) and
                grid[newX][newY]!='O' and
                visited[newX][newY]==0)
                {
                    visited[newX][newY]=1;
                    parent[newX][newY]=head;
                    q.push(adj_node);
                }
        }
    }

}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin>>c;
            grid[i][j]=c;
            if(c=='X')src={i,j};
            else if(c=='@')dst={i,j};
        }
    }

    parent[src.first][src.second]={-1,-1};
    bfs(src);

    if(visited[dst.first][dst.second]==0){
        cout<<"N\n";
        return 0;
    }

    cout<<"Y\n";
    pr selected_node=dst;
    grid[src.first][src.second]='+';
    while(1){
        if(selected_node==src)break;
        selected_node=parent[selected_node.first][selected_node.second];
        grid[selected_node.first][selected_node.second]='+';
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }


    return 0;
}
