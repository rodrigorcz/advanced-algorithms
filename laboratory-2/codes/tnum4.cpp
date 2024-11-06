#include <iostream>
#include <vector>

using namespace std;

int main(){
  long long p;
  cin >> p;

  vector<long long> res(p, -1);

  for(long long x = 0; x < p-1; x++){
    long long index = (x*x) % p;

    if(res[index] == -1) 
      res[index] = x % p;
  }

  for(auto r: res)
    cout << r << " ";

  return 0;
}