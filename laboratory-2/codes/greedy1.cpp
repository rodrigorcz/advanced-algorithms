#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  
  if(n == 0){
    cout << "sem reunioes hoje" << endl;
    return 0;
  }

  priority_queue<
      pair<int, int>,
      vector<pair<int, int>>,
      greater<pair<int, int>>
  > funcionarios;

  for(int i = 0; i < n; i++){
    int first, second;

    cin >> first >> second;

    //Invertendo pra facilitar
    funcionarios.push(make_pair(second, first));
  }

  int aux = -1;

  for(int i = 0; i < n;  i++){
    pair<int, int> currnt = funcionarios.top();

    if(currnt.second >= aux){
      cout << currnt.second << " " << currnt.first << endl;
      aux = currnt.first;
    }

    funcionarios.pop();
  }
  
  return 0;
}