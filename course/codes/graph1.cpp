#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

const int MAXN = 1000; 
const int INF = 1e9;   

int capacity[MAXN][MAXN];
vector<int> adj[MAXN];
int parent[MAXN];

bool bfs(int source, int sink) {
    memset(parent, -1, sizeof(parent));
    queue<pair<int, int>> q;
    q.push({source, INF});
    parent[source] = source;

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == sink)
                    return true;
                q.push({next, new_flow});
            }
        }
    }
    return false;
}

int maxFlow(int source, int sink) {
    int flow = 0;

    while (bfs(source, sink)) {
        int cur_flow = INF;
        int cur = sink;

        while (cur != source) {
            int prev = parent[cur];
            cur_flow = min(cur_flow, capacity[prev][cur]);
            cur = prev;
        }

        cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= cur_flow;
            capacity[cur][prev] += cur_flow;
            cur = prev;
        }

        flow += cur_flow;
    }
    return flow;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        memset(capacity, 0, sizeof(capacity));
        for (int i = 0; i < MAXN; ++i) adj[i].clear();

        map<char, int> task_demand;
        int total_demand = 0;

        int source = 0, sink = 1;
        int node_id = 2;

        map<char, int> task_node;
        map<int, int> proc_node;

        do {
            if (line.empty()) break;

            char task = line[0];
            int demand = line[1] - '0';
            total_demand += demand;

            int task_id = node_id++;
            task_node[task] = task_id;

            adj[source].push_back(task_id);
            adj[task_id].push_back(source);
            capacity[source][task_id] = demand;

            for (size_t i = 3; i < line.size(); ++i) {
                if (line[i] == ';') break;

                int proc = line[i] - '0';
                int proc_id = 50 + proc; 

                if (proc_node.find(proc) == proc_node.end()) {
                    proc_node[proc] = proc_id;
                    adj[proc_id].push_back(sink);
                    adj[sink].push_back(proc_id);
                    capacity[proc_id][sink] = 1;
                }

                adj[task_id].push_back(proc_id);
                adj[proc_id].push_back(task_id);
                capacity[task_id][proc_id] = 1;
            }
        } while (getline(cin, line) && !line.empty());

        int flow = maxFlow(source, sink);
        cout << (flow == total_demand ? "YES" : "NO") << endl;
    }

    return 0;
}