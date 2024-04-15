#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dynamic_prog(int *gomo, int n){
    vector<int> results(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        results[i] = gomo[i - 1];

        for (int j = 1; j < i; j++){
            results[i] = max(results[j] + results[i - j], results[i]);
        }
    }

    return results[n];
}

int main(){

    int n;
    cin >> n;

    int gomos[n];

    for(int i = 0; i<n; i++)
        cin >> gomos[i];
    
    int x = dynamic_prog(gomos, n);
    cout << x;

    return 0;
}
