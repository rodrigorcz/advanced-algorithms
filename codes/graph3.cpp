#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

void dfs(int v, vector<bool> &visitado, stack<int> &pilha, vector<vector<int>> grafo){
    visitado[v] = true;

    for (int u : grafo[v]) {
        if (!visitado[u])
            dfs(u, visitado, pilha, grafo);
    }

    pilha.push(v);
}

void dfs_util(int v, vector<int> &cor, vector<vector<int>> grafo, int var, int &contagem){
    cor[v] = var;
    contagem++;

    for (int u : grafo[v]) {
        if (cor[u] == 0)
            dfs_util(u, cor, grafo, var, contagem);
    }
}

vector<int> kosaraju(vector<vector<int>> grafo, vector<vector<int>> grafoT, int n) {
    stack<int> pilha;
    vector<bool> visitado(n, false);

    for(int i = 0; i < n; i++){
        if(!visitado[i])
            dfs(i, visitado, pilha, grafo);
    }

    vector<int> vist(n, 0);
    vector<int> cont(n+1);

    int cor = 1;

    while (!pilha.empty()){
        int v = pilha.top();
        pilha.pop();

        if (vist[v] == 0){
            int contagem = 0;
            dfs_util(v, vist, grafoT, cor++, contagem);
            cont[cor-1] = contagem;
        }
    }

    vector<int> componentes;

    for(int i = 0; i<vist.size(); i++){
        int cor = vist[i];

        if(cor == 0) continue;

        for(int j = 0; j<vist.size(); j++){
            if(cor == vist[j])
                vist[j] = 0;
        }

        componentes.emplace_back(cont[cor]);
    }

    return componentes;
}

int main() {
    while(true){
        int n_pessoas, m_relacoes;
        cin >> n_pessoas >> m_relacoes;

        if(n_pessoas == 0 && m_relacoes == 0) break;

        vector<vector<int>> graph(n_pessoas);
        vector<vector<int>> graph_tr(n_pessoas);

        for (int i = 0; i < m_relacoes; i++){
            int u, v, r;
            cin >> u >> v >> r;

            u--;
            v--;

            graph[u].push_back(v);
            graph_tr[v].push_back(u);

            if(r == 2){
                graph[v].push_back(u);
                graph_tr[u].push_back(v);
            }
        }

        vector<int> componentes = kosaraju(graph, graph_tr, n_pessoas);

        if(componentes.size() == 1)
            cout << "amor total" << endl;
        else{
            int i = 0;
            //sort(componentes.begin(), componentes.end());
            for(auto comp : componentes)
                cout << "[" << ++i << "," << comp << "]";

            cout << endl;
        }
    }

    return 0;
}
