#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct lista{
    int destino;
    struct lista *prox;
}lista;

typedef struct grafo{
    int origem;
    lista *destinos;
}grafo;

grafo *cria_grafo(int vertices);
void inserir_lista(lista **lista_adj, lista *nova_aresta);
void dfs(int v, vector<bool> &visitado, stack<int> &pilha, grafo *grafo);
void dfs_util(int v, vector<bool> &visitado, grafo *g, int &contagem);
int kosaraju(grafo *g, int V);

int main(){

    int n_cidades, m_voos;
    cin >> n_cidades >> m_voos;

    grafo *grafo_cidades = cria_grafo(n_cidades+1);

    for(int i = 0; i < m_voos; i++){
        int origem, destino;
        cin >> origem >> destino;

        lista *novo_no = (lista *) malloc(sizeof(lista));
        novo_no->destino = destino;
        novo_no->prox = NULL;

        grafo_cidades[origem].origem = origem;
        inserir_lista(&grafo_cidades[origem].destinos, novo_no);
    }

    if(kosaraju(grafo_cidades, n_cidades + 1) == 1)
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

    return 0;
}

grafo *cria_grafo(int vertices){
    grafo *novo_grafo = (grafo *) malloc((vertices+1)*sizeof(grafo));

    if (novo_grafo == NULL) exit(0);

    for (int i = 0; i < vertices; i++){
        novo_grafo[i].origem = -1;
        novo_grafo[i].destinos = NULL; 
    }

    return novo_grafo;
}

void inserir_lista(lista **lista_adj, lista *nova_aresta){

    if(*lista_adj == NULL || nova_aresta->destino <= (*lista_adj)->destino ) {
        nova_aresta->prox = *lista_adj;
        *lista_adj = nova_aresta; 
    }else{
        lista *tmp = *lista_adj;

        while(tmp->prox != NULL && nova_aresta->destino > (*lista_adj)->destino)
            tmp = tmp->prox;

        nova_aresta->prox = tmp->prox;
        tmp->prox = nova_aresta;
    }
}

void dfs(int v, vector<bool> &visitado, stack<int> &pilha, grafo *grafo) {
    visitado[v] = true;

    lista *adj = grafo[v].destinos;
    while (adj != NULL) {
        if (!visitado[adj->destino])
            dfs(adj->destino, visitado, pilha, grafo);
        adj = adj->prox;
    }

    pilha.push(v);
}

void dfs_util(int v, vector<bool> &visitado, grafo *g) {
    visitado[v] = true;

    lista *adj = g[v].destinos;
    while (adj != NULL) {
        if (!visitado[adj->destino])
            dfs_util(adj->destino, visitado, g);
        adj = adj->prox;
    }
}

grafo *transpor_grafo(grafo *g, int V) {
    grafo *gT = cria_grafo(V);
    
    for (int v = 0; v < V; v++) {
        lista *tmp = g[v].destinos;
        while (tmp != NULL) {
            lista *novo_no = (lista *) malloc(sizeof(lista));
            novo_no->destino = v;
            novo_no->prox = NULL;
            inserir_lista(&gT[tmp->destino].destinos, novo_no);
            tmp = tmp->prox;
        }
    }
    
    return gT;
}

int kosaraju(grafo *g, int vertices) {
    stack<int> pilha;
    vector<bool> visitado(vertices, false);

    for (int i = 0; i < vertices; i++)
        if (g[i].origem != -1 && !visitado[i])
            dfs(i, visitado, pilha, g);

    grafo *gT = transpor_grafo(g, vertices);

    fill(visitado.begin(), visitado.end(), false);

    int flag = 0;
    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();

        if (!visitado[v]) {
            dfs_util(v, visitado, gT);
            flag++;
        }
    }

    return flag;
}


