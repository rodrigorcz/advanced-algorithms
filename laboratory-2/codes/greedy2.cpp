#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> indexes(n) ;
    
    for(int i = 0; i < n ; i++){
        int inpt;
        cin >> inpt;
        
        indexes[inpt] = i;
    }
    
    int qtd = 1;
    
    for(int i = 0 ; i < n ; i++)
        if(indexes[i] > indexes[i+1]) qtd++;
    
    cout << qtd << endl;
    
    return 0;
}