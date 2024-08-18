#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int num_changes(string str1, string str2){
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> memo(n + 1, vector<int>(m + 1 , 0));

    for(int i = 0; i <= n; i++) memo[i][0] = i;
    for(int j = 0; j <= m; j++) memo[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i - 1] == str2[j - 1])
                memo[i][j] = memo[i - 1][j - 1];
            else
                memo[i][j] = 1 + min({memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]});
        }
    }

    return memo[n][m];
}

int main(){

    int n;
    string aux;
    getline(cin, aux);

    n = (int)aux[0] - 48;

    for(int i = 0; i < n; ++i){
        string str1, str2;
        getline(cin, str1);        
        getline(cin, str2);

        if(str1.size()==0 && str2.size()==0){
            cout << "0" << endl;
        }else
            cout << num_changes(str1, str2) << endl;
    }

    return 0;
}

