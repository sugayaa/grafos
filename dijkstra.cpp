#include<iostream>
#include<vector>
#include<queue>
#define pb push_back
#define N 	112345
#define INF	0x3F3F3F3F
#define fori(x) for(int i = 0; i < x; i++)
using namespace std;


typedef struct vertex{
	int index, weight;
}vertex;

vector <vertex> g[N];


bool operator>(const vertex& v, const vertex& v2)
{
	if (v.weight > v2.weight)
		return true;
	return false;
}

long dijkstra(long source, long destination)
{

	long dist[N];
	bool vis[N];
	priority_queue< vertex, vector<vertex>, greater<vertex> > pq;

	fori(N)
	{
		dist[i] = INF;
		vis[i] 	= false;
	}
	dist[source] = 0;


	vertex s;
	s.index = source;
	s.weight = 0;
	pq.push(s);

	while(!pq.empty())
	{
		long u = pq.top().index;
		pq.pop();

		if ( vis[u] ) continue;
		vis[u] = true;

		if ( u == destination ) return dist[u];

		fori(g[u].size())
		{
			vertex neighbor = g[u][i];

			if ( dist[u] + neighbor.weight < dist[neighbor.index] )
			{
				dist[neighbor.index] = dist[u] + neighbor.weight;
				neighbor.weight = dist[neighbor.index];
				pq.push(neighbor);
			}
		}

	}

	return -1;
}

int main(void)
{
	vertex t;
	t.index = 1;
	t.weight = 4;
	g[0].pb(t);

	t.index = 2;
	t.weight = 2;
	g[0].pb(t);

	t.index = 3;
	t.weight = 5;
	g[0].pb(t);

	t.index = 4;
	t.weight = 1;
	g[1].pb(t);

	t.index = 1;
	t.weight = 1;
	g[2].pb(t);

	t.index = 3;
	t.weight = 2;
	g[2].pb(t);

	t.index = 4;
	t.weight = 1;
	g[2].pb(t);

	t.index = 4;
	t.weight = 1;
	g[3].pb(t);

	cout << dijkstra(0,4) << endl;

	return 0;
}
