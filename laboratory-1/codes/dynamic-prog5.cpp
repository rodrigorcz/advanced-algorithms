#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1000000007

int num_paths(vector<vector<char>>& grid, vector<vector<int>>& memo, int i, int j){

    if(i < 0 || j < 0) return 0;
    if(grid[i][j] == '*') return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(i == 0 && j == 0) return 1;

    return memo[i][j] = (num_paths(grid, memo, i, j-1) % MOD + num_paths(grid, memo, i-1, j) % MOD) % MOD;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> memo(n, vector<int>(n, -1));
    vector<vector<char>> grid(n,  vector<char>(n));
   
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    int x = num_paths(grid, memo, n-1, n-1);
    cout << x ;

    return 0;
}

   

