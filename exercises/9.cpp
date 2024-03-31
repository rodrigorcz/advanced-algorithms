#include <iostream>
#include <vector>

using namespace std;

bool backtracking(int first, int last, int index, vector<pair<int, int>> pieces, vector<bool> remove,  int max){
    if(first == last && index == max)
        return true;

    if(index > max)
        return false;

    for(int i = 0; i < pieces.size(); i++){
        if(remove[i] != false){
            int flag = 0;
            pair<int, int> current = pieces[i];
            remove[i] = false;

            if(current.first == first){
                if(backtracking(current.second, last, index+1, pieces, remove, max))
                    return true; 
            }else if(current.second == first){
                if(backtracking(current.first, last, index+1, pieces, remove, max))
                    return true;
            }

            remove[i] = true;
        }
    }    

    return false;  
}

int main(){

    while(1){
        int n_spaces, m_pieces;
        cin >> n_spaces;

        if(n_spaces == 0)
            break;
        
        cin >> m_pieces;

        pair<int, int> first, last;
        cin >> first.first >> first.second;
        cin >> last.first >> last.second;

        vector<pair<int, int>> pieces; 

        for(int j = 0; j < m_pieces; j++){
            int right, left;
            cin >> right >> left;

            pieces.push_back({right, left});
        }

        vector<bool> bool_vector (m_pieces, true);
        
        if(backtracking(first.second, last.first, 0, pieces, bool_vector, n_spaces))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}


