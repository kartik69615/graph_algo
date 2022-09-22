#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<int> adj[] , int v)
{
    vector<int> res;
    vector<int> vis(v+1 , 0);

    for(int i=1 ; i<=v ; i++)
    {
        if(vis[i] == 0)
        {
            queue<int> level;
            level.push(i);
            vis[i] = 1;

            while(!level.empty())
            {
                int node = level.front();
                level.pop();
                res.push_back(node);

                for(auto itr : adj[node])
                {
                    if(vis[itr] == 0)
                    {
                        level.push(itr);
                        vis[itr] = 1;
                    }
                }
            }
        }
    }

    return res;

}

void print(vector<int> res)
{
    for(auto itr : res)
    {
        cout << itr << " ";
    }

    cout << endl;
}

// void print(vector<int> adj[] , int v)
// {
//     for(int i=1 ; i<=v ; i++)
//     {
//         cout << "Adj node of " << i << " : ";

//         for(auto itr : adj[i])
//         {
//             cout << itr << " ";
//         }

//         cout << endl;
//     }
// }

int main()
{
    int v , e;
    cin >> v >> e;
    vector<int> adj[v+1];

    for(int i=0 ; i<e ; i++)
    {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    print(bfs(adj , v));


    
    return 0;
}