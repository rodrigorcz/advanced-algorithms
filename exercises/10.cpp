#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<bool>> positions(8, vector<bool>(8, true));

int horse_moves[8][2] = {
        {-2, -1}, {-2, 1}, 
        {-1, -2}, {-1, 2}, 
        {1, -2}, {1, 2},   
        {2, -1}, {2, 1}    
};

bool valid(int x){
    if (x>=0 && x<8)
        return true;
    else
        return false;
}

void pos_horse(int lin, int col){
    positions[lin][col] = false;

    for(int i = 0; i<8; i++){
        int new_col = col + horse_moves[i][0];
        int new_lin = lin + horse_moves[i][1];

        if(valid(new_lin) && valid(new_col))
            if(positions[new_lin][new_col])
                positions[new_lin][new_col] = false;
    }
}

bool verify_horse(int lin, int col, pair<int, int> rk, pair<int, int> hs){
    if(!positions[lin][col])
        return false;
    else for(int i = 0; i<8; i++){
            int new_col = col + horse_moves[i][0];
            int new_lin = lin + horse_moves[i][1];

            if(valid(new_lin) && valid(new_col)){
                if(rk.first == new_lin && rk.second == new_col)
                    return false;
                
                if(hs.first == new_lin && hs.second == new_col)
                    return false;
            }
    }
    return true;
}

int main(){

    string rook, horse; 
    cin >> rook >> horse;

    int index = 0;

    int j_rook = rook[0] - 'a';
    int j_horse = horse[0] - 'a';

    int i_rook = stoi(rook.substr(1, 1))-1; 
    int i_horse = stoi(horse.substr(1, 1))-1; 

    pos_horse(i_horse,j_horse);

    for (int j = 0; j < 8; j++) 
        positions[i_rook][j] = false;

    for (int i = 0; i < 8; i++) 
        positions[i][j_rook] = false;

    for (int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if(verify_horse(i,j, {i_rook, j_rook}, {i_horse, j_horse}))
                index++;
        }
    }

    cout << index;
    return 0;
}