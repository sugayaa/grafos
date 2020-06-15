#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MAX 10000
using namespace std;

int G[MAX][MAX];
vector<pair<int,int> > v[MAX];
int vis[MAX];
queue < pair<int, int> > q;

int bfsM(int s, int t){
	pair <int,int> node = mp(s,0);

	q.push(node);

	while(!q.empty()){
		node = q.front();
		int ind = node.first;
		int custo = node.second;
		q.pop();
		if(t == ind)return custo;

		for(int g = 0; g < MAX; g++){
			if(G[ind][g]){
				if(vis[g]) continue;
				else vis[g] = 1;
				q.push(mp(g,custo+1));
			}
		}
	}
}


int bfsV(int s, int t){
	pair <int, int> node = mp(s,0);
	q.push(node);

	while(!q.empty()){
		node = q.front();
		int ind = node.first;
		int custo = node.second;
		q.pop();
		if(t == ind)return custo;

		for(int g = 0; g < v[ind].size(); g++){
			if(vis[v[ind][g].first]) continue;
			else vis[v[ind][g].first] = 1;
			q.push(mp(v[ind][g].first,custo+1));
			
		}
	}
}

int main(){
	//Inserir N grafos
	//int n;
	//cin >> n;
	//
	//while(n--){


		//zerando todos os elementos que podem ser utilizados
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < MAX; i++){
			memset(G[i], 0, sizeof(G[i]));
			v[i].clear();
		}

		int a, b, c, source, target;

		//lendo grafo ñ valorado
		cout << "Defina as arestas do seu grafo não valorado digitando os dois vértices que cada uma conecta." << endl;
		cout << "Para indicar o fim do seu grafo, digite '0 0'" << endl;
		while((cin >> a >> b) && (a != 0 || b != 0)){
			G[a][b] = 1;
			G[b][a] = 1;
			v[a].pb(mp(b,1));
			v[b].pb(mp(a,1));
		}

		//lendo grafo valorado
		/*
		cout << "Defina as arestas do seu grafo valorado digitando os dois vértices que cada uma conecta e em seguida seu peso." << endl;
		cout << "Para indicar o fim do seu grafo digite '0 0 0'" << endl;
		while((cin >> a >> b >> c)  && (a != 0 || b != 0 || c != 0)){
			G[a][b] = c;
			G[b][a] = c;
			v[a].pb(mp(b,c));
			v[b].pb(mp(a,c));
		}
		*/
		cout << "Digite o vértice origem e o vértice destino da sua navegação: " << endl;
		cin >> source >> target;


		//usando matriz de adjacência
		cout << bfsM(source, target) << endl;

		//usando vetor de listas de adjacência
		//cout << bfsV(source, target) << endl;

/*
	} fim do while para ler N grafos */

}
