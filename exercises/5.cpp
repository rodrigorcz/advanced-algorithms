#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(int argc, char * argv[]){

    int h;
    cin >> h;

    priority_queue<int> fila;

    for(int i =0; i<12; i++){
        int cent;
        cin >> cent;
        fila.push(cent);
    }

    int total = 0;
    int j;

    for(j = 1; j<=12; j++){
        int maior = fila.top();
        total = total + maior;

        if(total >= h){
            cout << j; 
            break;
        }
        fila.pop();
    }

    if(j>=13)
        cout << "nao cresce";
}
