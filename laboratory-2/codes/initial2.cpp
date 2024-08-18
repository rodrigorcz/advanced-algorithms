#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int soma = (1+n)*n/2;
    
    vector<int> A;
    vector<int> B ;
    
    if(soma % 2 != 0){
        cout << "NAO";
    }else{
        cout << "SIM" << endl;
        int alvo = soma/2;
        for(int i = n; i>0; i--){
            if(i <= alvo){
                A.push_back(i);
                alvo -= i;
            }else
                B.push_back(i);
        }
        
        cout << A.size() << endl;
        for (int i = A.size() - 1; i >= 0; i--) 
            cout << A[i] << " "; 
            
        cout << "\n" << B.size() << endl;
        for (int i = B.size() - 1; i >= 0; i--) 
            cout << B[i] << " "; 
        
    }
    
    return 0;
}