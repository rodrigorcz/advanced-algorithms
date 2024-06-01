#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define MOD 1000000007

using namespace std;

typedef struct lista{
    int destino;
    long long preco;
    struct lista *prox;
}lista;

typedef struct grafo{
    int origem;
    lista *destinos;
}grafo;

grafo *cria_grafo(int vertices);
void inserir_lista(lista **lista_adj, lista *nova_aresta);
void dijkstra(grafo *g, int origem, int destino, int num_vertice);

int num_rotas, min_voos, max_voos;
long long preco_min;

int main(){

    int n_cidades, m_voos;
    cin >> n_cidades >> m_voos;

    grafo *grafo_cidades = cria_grafo(n_cidades+1);

    for(int i = 0; i < m_voos; i++){
        int origem, destino;
        long long preco;
        cin >> origem >> destino >> preco;

        lista *novo_no = (lista *) malloc(sizeof(lista));
        novo_no->destino = destino;
        novo_no->preco = preco;
        novo_no->prox = NULL;

        grafo_cidades[origem].origem = origem;
        inserir_lista(&grafo_cidades[origem].destinos, novo_no);
    }

    dijkstra(grafo_cidades, 1, n_cidades, n_cidades + 1);

    cout << preco_min << " " << num_rotas % MOD << " " << min_voos << " " << max_voos << endl;

    return 0;
}

grafo *cria_grafo(int vertices){
    grafo *novo_grafo = (grafo *) malloc((vertices+1)*sizeof(grafo));

    if(novo_grafo == NULL) exit(0);

    for(int i = 0; i < vertices; i++){
        novo_grafo[i].origem = -1;
        novo_grafo[i].destinos = NULL; 
    }

    return novo_grafo;
}

void inserir_lista(lista **lista_adj, lista *nova_aresta){
    nova_aresta->prox = *lista_adj;
    *lista_adj = nova_aresta; 
}

void dijkstra(grafo *g, int origem, int destino, int num_vertice) {
    vector<long long> dist(num_vertice, LLONG_MAX);
    vector<int> count(num_vertice, 0);
    vector<int> min_flights(num_vertice, INT_MAX);
    vector<int> max_flights(num_vertice, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[origem] = 0;
    count[origem] = 1;
    min_flights[origem] = 0;
    max_flights[origem] = 0;
    pq.push({0, origem});

    while(!pq.empty()){
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        lista *tmp = g[u].destinos;
        
        while(tmp != NULL){
            int v = tmp->destino;
            long long peso = tmp->preco;

            if(dist[u] + peso < dist[v]){
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
                count[v] = count[u];
                min_flights[v] = min_flights[u] + 1;
                max_flights[v] = max_flights[u] + 1;

            }else if (dist[u] + peso == dist[v]){
                count[v] = (count[v] + count[u]) % MOD;
                min_flights[v] = min(min_flights[v], min_flights[u] + 1);
                max_flights[v] = max(max_flights[v], max_flights[u] + 1);
            }

            tmp = tmp->prox;
        }
    }

    preco_min = dist[destino];
    num_rotas = count[destino];
    min_voos = min_flights[destino];
    max_voos = max_flights[destino];
}


