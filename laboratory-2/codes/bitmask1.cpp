#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int tsp(int mask, int pos, const vector<vector<int>>& dist, vector<vector<int>>& dp, int n, int start) {

    if (mask == (1 << n) - 1) return dist[pos][start];

    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;

    for(int city = 0; city < n; ++city){
        if((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n, start);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n, start;
    cin >> n >> start;

    vector<vector<int>> dist(n, vector<int>(n));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout << tsp(1 << start, start, dist, dp, n, start) << endl;

    return 0;
}
