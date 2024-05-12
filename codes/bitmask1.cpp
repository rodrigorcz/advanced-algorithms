#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

#define MOD 1000000007;

int n, m;

int solve(int roupa, int mask, vector<vector<int>>& lista_roupas, vector<vector<int>>& memo) {

    if(mask == (1 << n) - 1) return 1;
    if(roupa >= m) return 0;
    if(memo[roupa][mask] != -1) return memo[roupa][mask];

    int total = solve(roupa + 1, mask, lista_roupas, memo);

    for(int nxt = 0; nxt < lista_roupas[roupa].size(); ++nxt){
        if(!(mask & (1 << lista_roupas[roupa][nxt])))
            total = (total + solve(roupa + 1, mask | (1 << lista_roupas[roupa][nxt]), lista_roupas, memo)) % MOD;
    }

    return memo[roupa][mask] = total;
}

int main(){
    cin >> n >> m;

    vector<vector<int>> lista_roupas(m);
    vector<vector<int>> memo(m, vector<int>(1 << n, -1));

    for (int i = 0; i < n; ++i) {
        int n_colecoes;
        cin >> n_colecoes;

        for (int j = 0; j < n_colecoes; ++j) {
            int id;
            cin >> id;

            lista_roupas[id-1].push_back(i);
        }
    }

    cout << solve(0, 0, lista_roupas, memo);
    
    return 0;
}