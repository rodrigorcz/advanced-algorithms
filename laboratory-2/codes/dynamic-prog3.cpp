#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string output;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int alpha3(char str1, char str2){
    if(is_vowel(str1) && is_vowel(str2)) return 1;
    if(!is_vowel(str1) && !is_vowel(str2)) return 1;
    
    return 3;
}

void num_changes(string str1, string str2, vector<vector<int>> &memo){
    int n = str1.size();
    int m = str2.size();

    for (int i = 0; i <= n; i++) memo[i][0] = 2 * i;
    for (int j = 0; j <= m; j++) memo[0][j] = 2 * j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            if(str1[i - 1] == str2[j - 1]){
                memo[i][j] = memo[i - 1][j - 1];
            }else{
                int a = memo[i - 1][j] + 2;  //remover   
                int b = memo[i][j - 1] + 2;  //inserir  
                int c = memo[i - 1][j - 1] + alpha3(str1[i - 1], str2[j - 1]); 

                memo[i][j] = min({a, b, c});
            }
        }
    }
}


void find_output(string str1, string str2, vector<vector<int>> &memo, int n, int m){
    int i = n, j = m;
    while(i > 0 || j > 0){
        if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]){
            i--; j--;
        }else if(i > 0 && memo[i][j] == memo[i - 1][j] + 2){
            output = "R:" + string(1, str1[i - 1]) + output;
            i--;
        }else if(j > 0 && memo[i][j] == memo[i][j - 1] + 2){
            output = "I:" + string(1, str2[j - 1]) + output;
            j--;
        }else if(i > 0 && j > 0 && memo[i][j] == memo[i - 1][j - 1] + alpha3(str1[i - 1], str2[j - 1])){
            output = "T:" + string(1, str1[i - 1]) + "-" + string(1, str2[j - 1]) + output;
            i--; j--;
        }
    }
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));

    output = "";

    if(n == 0 && m == 0){
        cout << "0\n nada a fazer" << endl;
    }else{
        num_changes(str1, str2, memo);
        (!memo[n][m])? cout << "0\nnada a fazer": cout << memo[n][m] << endl;
    }
    find_output(str1, str2, memo, n, m);
    cout << output << endl;
    return 0;
}