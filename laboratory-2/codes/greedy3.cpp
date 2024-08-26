#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;

  priority_queue<
      pair<int, int>,
      vector<pair<int, int>>,
      greater<pair<int, int>>
  > fila;

  for(int i = 0; i< n; i++){
    int t, d;
    cin >> t >> d;

    fila.push(make_pair(t , d));
  }

  int cust, stack;
  cust = stack = 0;

  for(int i = 0; i<n; i++){
    pair<int, int> aux = fila.top();
    fila.pop();

    cust = cust + aux.second - (aux.first + stack);
    stack = stack + aux.first;
  } 

  cout << cust << endl;

  return 0;
}