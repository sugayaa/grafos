#include<bits/stdc++.h>
#define MAX 11234
#define pb push_back
using namespace std;

typedef struct vertex
{
    long v, w;
}vertex;

vector <vertex> G[MAX];


void add_conn( int u, int v, int w )
{
    vertex n = { .v = v, .w = w };
    G[u].pb(n);

    n = { .v = u, .w = w };
    G[v].pb(n);
}

void add_conn_uni( int u, int v, int w )
{
    vertex n = { .v = v, .w = w };
    G[u].pb(n);
}

void print(){
    int i;
    for(i = 0; i < MAX; i++)
    {
        if( !G[i].empty() )
        {
            for(unsigned long j = 0; j < G[i].size(); j++)
            {
                cout << "Vertex from " << i << " to " << G[i][j].v << " with weigth " << G[i][j].w << endl;
            }
        }
    }
}


int main(void)
{
    long nvertex;
    cout << "How many vertexes?" << endl;
    cin >> nvertex;

    long u, v, w;

    cout << "Allright, " << nvertex << " vertexes," << endl;
    cout << "now enter each one with, source, destination and weigth respectively" << endl;
    cout << "Something like: " << endl << "1 2 10 " << endl;
    cout << "Connecting edge 1 to 2, with 10 as weigth" << endl;

    while(nvertex--)
    {
        cin >> u >> v >> w;

        add_conn( u, v, w );
    }

    print();

    return 0;
}
