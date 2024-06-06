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

void dfs_util(int v, vector<bool> &visitado, vector<vector<int>> grafo, int &contagem){
    visitado[v] = true;
    contagem++;

    for (int u : grafo[v]) {
        if (!visitado[u])
            dfs_util(u, visitado, grafo, contagem);
    }
}

vector<pair<int, int>> kosaraju(vector<vector<int>> grafo, vector<vector<int>> grafoT, int n) {
    stack<int> pilha;
    vector<bool> visitado(n, false);

    for(int i = 0; i < n; i++){
        if(!visitado[i])
            dfs(i, visitado, pilha, grafo);
    }

    fill(visitado.begin(), visitado.end(), false);

    vector<pair<int, int>> componentes;
    int flag = 0;

    while (!pilha.empty()){
        int v = pilha.top();
        pilha.pop();

        if (!visitado[v]){
            int contagem = 0;
            dfs_util(v, visitado, grafoT, contagem);
            componentes.push_back({++flag, contagem});
        }
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

        vector<pair<int, int>> componentes = kosaraju(graph, graph_tr, n_pessoas);

        if(componentes.size() == 1)
            cout << "amor total" << endl;
        else{
            for(auto comp : componentes)
                cout << "[" << comp.first << "," << comp.second << "]";

            cout << endl;
        }
    }

    return 0;
}
