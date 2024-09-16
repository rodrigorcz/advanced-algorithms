#include <iostream>
#include <bits/stdc++.h>
#include <climits>
#include <cstring>

using namespace std;

int n, m, l;
bool visited[25][25]; 

void backtracking(vector<vector<int>>&paths, int curnt, int curr_path){
    l = max(l, curr_path);

    for(int i = 0; i < paths[curnt].size(); ++i){
        int next_node = paths[curnt][i];

        if(!visited[curnt][next_node]){
            visited[curnt][next_node] = visited[next_node][curnt] = true; 
            backtracking(paths, next_node, curr_path + 1); 
            visited[curnt][next_node] = visited[next_node][curnt] = false; 
        }
    }
}


int main(){

    while(1){
        cin >> n >> m;
        if(n == 0 || m == 0) break;
        
        vector<vector<int>> paths(n);
        memset(visited, false, sizeof(visited));

        for(int i = 0; i<m; i++){
            int x, y;
            cin >> x >> y;
            paths[x].push_back(y);
            paths[y].push_back(x);
        }
        
        l = INT_MIN;

        for(int i = 0; i < n; ++i) 
            backtracking(paths, i, 0);

        cout << l << endl;
    }

    return 0;
}