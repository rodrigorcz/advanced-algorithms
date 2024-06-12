#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n_pilhas, jogador;
    cin >> n_pilhas >> jogador;

    vector<int> pilhas(n_pilhas);

    for(int i = 0; i < n_pilhas; i++)
        cin >> pilhas[i];
    
    int nim = 0;
    for(int i = 0; i < n_pilhas; i++) 
        nim ^= pilhas[i];
    
    
    if(nim == 0) 
        cout << "Jogador " << jogador << " perdeu o jogo!" << endl;
    else 
        cout << "Jogador " << jogador << " ganhou o jogo!" << endl;
    

    return 0;
}
