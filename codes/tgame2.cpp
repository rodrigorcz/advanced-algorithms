#include <iostream>
#include <vector>
#include <set>
#include<unordered_set>

using namespace std;

int mex(unordered_set<int>& s) {
    int mexValue = 0;
    while (s.find(mexValue) != s.end()) {
        mexValue++;
    }
    return mexValue;
}


int grundy(int n, vector<int>& GN) {
    if (n < 4) return n;  
    if (GN[n] != -1) return GN[n];  

    unordered_set<int> s;
    for(int i = 1; i <= n / 2; i++){
        if (i != n / 2) 
            s.insert(grundy(n - i, GN));
    }

    GN[n] = mex(s);  
    return GN[n];
}

int main() {
    int t;
    cin >> t;

    vector<int> valores(t);
    int maxN = 0;

    for(int i = 0; i < t; i++){
        cin >> valores[i];
        if (valores[i] > maxN) maxN = valores[i];
    }

    vector<int> GN(maxN+1, -1);

    for(int i = 0; i <= maxN; i++)
        grundy(i, GN);

    for(int i = 0; i < t; i++){
        if(GN[valores[i]] != 0) 
            cout << "primeiro" << endl;
        else 
            cout << "segundo" << endl;        
    }

    return 0;
}
