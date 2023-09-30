#include <bits/stdc++.h>
using namespace std;
/*
2 3
3 2 4
1 5 1

*/

const int N = 100;
typedef pair<int, int> intpr;

int maze[N][N];
vector<int> parent[N];
int n, m;
int ans = 0;

bool is_inside(int x, int y)
{
    if (x >= 0 and x < n and y >= 0 and y < m)
        return true;
    return false;
}

void bfs(intpr src)
{
    queue<intpr> q;
    q.push(src);

    while (!q.empty())
    {
        intpr head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        ans = ans + maze[x][y];
        if (x == 0 and y == m - 1)
            break;

        int tx1 = x + 0;
        int ty1 = y + 1;
        int tx2 = x - 1;
        int ty2 = y + 0;
        int newX;
        int newY;
        int op1 = 0;

        if (is_inside(tx1, ty1))
        {
            op1 = maze[tx1][ty1];
        }

        int op2 = 0;
        if (is_inside(tx2, ty2))
        {
            op2 = maze[tx2][ty2];
        }

        if (op1 > op2)
        {
            newX = tx1;
            newY = ty1;
        }
        else
        {
            newX = tx2;
            newY = ty2;
        }

        intpr adj_node = {newX, newY};
        q.push(adj_node);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int inp;
            cin >> inp;
            maze[i][j] = inp;
        }
    }

    intpr src = {n - 1, 0};
    bfs(src);
    cout << ans << endl;

    return 0;
}
