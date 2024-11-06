#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <climits>

using namespace std;

typedef long long ll;

ll tam;
bitset<100010> sieve; // crivo
vector<int> primes;

void find_sieve(ll max){
  tam = max+1;

  sieve.set();
  sieve[0] = sieve[1] = 0;

  for(ll i = 2; i<=tam; i++){
    if(sieve[i]){
      primes.push_back(int(i));

      for(ll j = i*i; j<=tam; j += i) sieve[j] = 0;
    }
  } 
}

bool is_prime(ll val){
  if(val <= 100000) 
    return sieve[val];

    for (int p : primes) {
        if (p * p > val) break; 
        if (val % p == 0) return false;
    }
  return true;
}

int find_closest(int val){
  int num;
  int mini = 100000;
  for(int p : primes){
    if((p - val) > 0 && (p - val) < mini){
      mini = p - val;
      num = p;
    }
    if (p > val) break; 
  }
  return mini;
}

int min_operations(vector<vector<int>> matrix, int n, int m){
  int min_row = INT_MAX;
  for(int i = 0; i < n; i++){
    int op = 0;
    for(int j = 0; j < m; j++){
      if(!is_prime(matrix[i][j])){
        int diff = find_closest(matrix[i][j]);
        op += diff;
      }
    }
    min_row = min(min_row, op);
  }

  int min_col = INT_MAX;
  for(int i = 0; i < m; i++){
    int op = 0;
    for(int j = 0; j < n; j++){
      if(!is_prime(matrix[j][i])){
        int diff = find_closest(matrix[j][i]);
        op += diff;
      }
    }
    min_col = min(min_col, op);
  }

  return min(min_col, min_row);
}

int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j)
      cin >> matrix[i][j];
  }

  find_sieve(100000);
  
  cout << min_operations(matrix, n, m) << endl;

  return 0;
}
