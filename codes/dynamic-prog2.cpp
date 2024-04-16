#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

#define INF INT_MAX-1

int search(int *options,  int *memo, int n, int v){

    if(n-1 <= v)
        return 0;

    if(memo[v] != -1)
        return memo[v];

    if(options[v] == 0)
        return INF;
        
    memo[v] = INF;

    for (int j = 1; j <= options[v]; j++){
        int next = v + j;
        if(next < n)
            memo[v] = min(search(options, memo, n, next) + 1, memo[v]);
    }

    return memo[v];
}

int main(){

    int n;
    cin >> n;

    int *options = new int[n];
    int *memo = new int[n];
    memset(memo, -1, n * sizeof(int));

    for(int i = 0; i<n; i++)
        cin >> options[i];

    int x = search(options, memo, n,  0);

    if(x >= INF || x < 0)
        cout << "Salto impossivel";
    else 
        cout << x;

    delete[] options;
    delete[] memo;

    return 0;
}