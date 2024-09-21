#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int n;
vector<long> ternos;

long dp(long index, vector<long> &memo){
  if(index == n - 1)
    return 0;

  if(memo[index] != -1)
    return memo[index];
  
  memo[index] = LONG_MAX - 1;

  for(int i = 1; i <= 2; ++i){
    if(index+i < n){
        long cust = abs(ternos[index] - ternos[index+i]);
        memo[index] = min(memo[index], dp(index+i, memo) + cust);  
    }
  }

  return memo[index];
}

int main(){
  cin >> n;

  for(int i = 0; i < n; i++){
    long x;
    cin >> x;
    ternos.push_back(x);
  }

  vector<long> memo(n, -1);

  cout << dp(0, memo) << endl;
}