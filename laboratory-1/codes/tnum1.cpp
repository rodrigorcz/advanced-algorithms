#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> n_primes(int upper){
    vector<int> prime;
    bitset<1000010> bs;

    bs.set();
    bs[0] = bs[1] = 0;

    for(long i = 2; i <= upper+1; i++){
        if(bs[i]){
            for(long j = i*i; j<= upper+1; j += i){
                bs[j] = 0;
            }
            prime.push_back((int)i);
        }
    } 

    return prime;
}

map<int, int> n_factors(int n, vector<int>& primes) {
    map<int, int> factors;
    long index = 0;
    long pf = primes[0];

    while(n!=1 && (pf*pf)<=n) {
        while (n % pf == 0) {
            n /= pf;
            factors[pf]++;
        }
        pf = primes[++index];
    }

    if(n != 1) factors[n]++;

    return factors;
}


int main(){
    int n;
    cin >> n;

    vector<int> prime = n_primes(10e5);

    for(int j = 0; j < n; j++){

        int x;
        cin >> x;

        map<int, int> factors = n_factors(x, prime);

        int total = 1;
        for (auto pair : factors) 
            total *= (pair.second + 1);
        
        cout << total << endl;
    }

    return 0;
}