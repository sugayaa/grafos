#include <bits/stdc++.h>
#define ll unsigned long long int
#define pb push_back
#define mp make_pair
#define _pq priority_queue
#define inf 0x3F3F3F3F
using namespace std;

typedef pair<int, int> ii;
int vertex_no;
ll weight_sum = 0;
list < ii > *adj;

void init_graph( int n )
{
    vertex_no = n;
    adj = new list< ii > [n];
    weight_sum = 0;
}

void add_edge( int u, int v, int w )
{
    adj[u].pb( mp(v, w) );
    adj[v].pb( mp(u, w) );
}

ll primMST()
{
    _pq< ii, vector < ii >, greater< ii > > pq;
    int src = 0;

    vector<int> key(vertex_no, inf);
    vector<int> parent(vertex_no, -1);
    vector<bool> inMST(vertex_no, false);

    pq.push( mp(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int  u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        list< ii >::iterator i;

        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push( mp(key[v], v) );
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < vertex_no; i++)
    {
        weight_sum += key[i];
    }

    return weight_sum;
}

int main(void)
{
    int nodes, edges;
    cin >> nodes >> edges;

    init_graph( nodes );

    while( edges-- )
    {
        int i, j, k;
        cin >> i >> j >> k;
        //if index starts at 1
        i--;
        j--;
        //
        add_edge(i, j, k);
    }

    cout << primMST() << endl;

    return 0;
}
