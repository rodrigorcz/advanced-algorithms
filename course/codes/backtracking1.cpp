#include <iostream>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int n, m, d = INT_MAX, q = 0;

int moves[4][2]= {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool is_valid(int x, int y){
    return x < n && y < m && x >= 0 && y >= 0 ;
}

void backtracking(vector<vector<bool>>&labrinth, int x, int y, int curnt){
    if(x == n-1 && y == m-1){
        d = min(d, curnt);
        q++;
    }else{
        for(int i = 0; i<4; i++){

            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if(is_valid(nx, ny) && labrinth[nx][ny]){
                labrinth[nx][ny] = false;
                backtracking(labrinth, nx, ny, curnt + 1);
                labrinth[nx][ny] = true;    
            }
        }
    }
}


int main(){

    cin >> n >> m;
    vector<vector<bool>> labrinth (n, vector<bool>(m, true));
    labrinth[0][0] = false;

    int x, y;
    while(cin >> x >> y)
        labrinth[x][y] = false;
    
    backtracking(labrinth, 0, 0, 0);

    cout << q << " " << d << endl; 

    return 0;
}