#include <bits/stdc++.h>
using namespace std;

const int N = 100;
typedef pair<int, int> intpr;

vector<intpr> adj_list[N];
int nodes, edges;
int adj_matrix[N][N];
/*
    4 4
    0 1 2
    1 2 4
    1 3 3
    2 3 2
*/

int main()
{
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    cout << "Adj List presentation:\n";
    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << "( " << adj_list[i][j].first << "," << adj_list[i][j].second << " )";
        }
        cout << "\n";
    }
    cout << "\nAdj Matrix presentation\n\n";
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            int u = i, v = adj_list[i][j].first, w = adj_list[i][j].second;
            adj_matrix[u][v] = w;
            adj_matrix[v][u] = w;
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
