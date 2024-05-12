#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int side, n;

bool solve(vector<int>& sticks, vector<int>& memo, int k, int curside, int mask, int i) {
    if(k == 1)
        return true;
        
    for(int j = i; j < sticks.size(); j++){
        if(!(mask & (1 << j))){
            int nxtside = curside + sticks[j];
            if(nxtside <= side){
                if(nxtside == side){
                    if (solve(sticks, memo, k - 1, 0, mask | (1 << j), 0))
                        return true;
                }else{
                    if (solve(sticks, memo, k, nxtside, mask | (1 << j), j + 1))
                        return true;
                }
            }
        }
    }

    return false;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; ++i){
        int m, sum = 0;
        cin >> m;

        vector<int> memo(m+1, -1);
        vector<int> sticks(m);

        for(int j = 0; j < m; ++j){
            int k;
            cin >> k;

            sticks[j] = k;
            sum += k;
        }

        if (sum % 4){
            cout << "nao" << endl;
            continue;
        }

        side = sum / 4;
        (solve(sticks, memo, 4, 0, 0, 0) == 1)? cout << "sim" : cout << "nao";
        cout << "\n";
    }

    return 0;
}

