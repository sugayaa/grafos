#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MAX 10000
using namespace std;
typedef pair<int,int> ii;

int G[MAX][MAX];
vector< ii > v[MAX];
int vis[MAX];


int dfsM(int c, int d, int t){

    vis[c] = 1;

    for(int n = 0; n < MAX; n++){
        //if there's a connection
        if(G[c][n]){
            if(vis[n]) continue;

            if (n == t) return d;
            else  return dfsM(n, d + G[c][n], t);

        }
    }
    //não achou
    return -1;
}

int dfsV(int c, int d, int t){
    vis[c] = 1;

    for( int n = 0; n < v[c].size() ; n++ ){
        int next = v[c][n].first;
        int weigth = v[c][n].second;
        if (vis[next]) continue;

        if (next == t) return d;
        else return dfsV(next, d + weigth, t);
    }
    return -1;
}


/*
 *UTILS
 */
void print(){
    for (int i = 0;i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if ( G[i][j] ){
                printf("Conexão de %d à %d\n", i, j);
            }
        }
    }
}

void reset_vis(){
    memset(vis, 0, sizeof(vis));
}

void initialize(){
    //zerando todos os elementos que podem ser utilizados
    reset_vis();
    for(int i = 0; i < MAX; i++){
        memset(G[i], 0, sizeof(G[i]));
        v[i].clear();
    }
}



int main(){
    //Inserir N grafos
    //int n;
    //cin >> n;
    //
    //while(n--){


    initialize(); 

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

    //bfs navigates paths
    //print();

    //usando matriz de adjacência
    cout << dfsV(source, 0, target) << endl;
    reset_vis();
    cout << dfsM(source, 0, target) << endl;

    //usando vetor de listas de adjacência
    //cout << bfsV(source, target) << endl;

    /*
       } fim do while para ler N grafos */

}
