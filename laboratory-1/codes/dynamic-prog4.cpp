#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

// knapsack problem
int num_pags(int n, int x, int *precos, int *paginas){

    vector<int> memo(x+1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= precos[i]; j--) {
            memo[j] = max(memo[j], memo[j - precos[i]] + paginas[i]);
        }
    }

    return memo[x];
}

int main(){
    int n, x;
    cin >> n >> x;

    int precos[n], paginas[n];

    for(int i = 0; i<n; i++) cin >> precos[i];

    for(int i = 0; i<n; i++) cin >> paginas[i];
    
    int var  = num_pags(n, x, precos, paginas);
    cout << var;

    return 0;
}

