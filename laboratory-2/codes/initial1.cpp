#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int p1, p2;
        cin >> p1 >> p2;
        
        if((p1+p2) % 3 == 0){
            if(max(p1, p2) > min(p1, p2)*2)
                cout << "NAO" << endl;
            else
                cout << "SIM" << endl;
        }else
            cout << "NAO" << endl;
        
    }
    return 0;
}