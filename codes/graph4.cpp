#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;

//EdmondsKarp 

long long bfs(int s, int t, vector<int>& parent, vector<vector<long long>> &capacity, vector<vector<int>> &graph){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, long long>> queue;
    queue.push({s, INF});

    while (!queue.empty()){
        int cur = queue.front().first;
        long long flow = queue.front().second;
        queue.pop();

        for (int next : graph[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0){
                parent[next] = cur;
                long long new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                queue.push({next, new_flow});
            }
        }
    }

    return 0;
}

long long flow(int s, int t, vector<vector<long long>> &capacity, vector<vector<int>> &graph, int n){
    long long max_flow = 0;
    vector<int> parent(n);
    long long new_flow;

    while ((new_flow = bfs(s, t, parent, capacity, graph))){
        max_flow += new_flow;
        int cur = t;

        while (cur != s){
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return max_flow;
}

int main(){
    int n, m; 
    cin >> n >> m;

    vector<vector<long long>> capacity(n + 1, vector<long long>(n + 1, 0));
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;

        capacity[a][b] += c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << flow(1, n, capacity, graph, n+1) << endl;

    return 0;
}
