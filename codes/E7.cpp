#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char *argv[]){
    int n_bachelor, n_spinster, index = 1;

    while(1){
        cin >> n_bachelor >> n_spinster;

        if(n_bachelor == 0 && n_spinster == 0)
            break;

        priority_queue<int, vector<int>, greater<int>> bachelor;

        for(int i = 0; i<n_bachelor; i++){
            int age_b;
            cin >> age_b;

            bachelor.push(age_b);
        }

        for(int j = 0; j<n_spinster; j++){
            int age_s;
            cin >> age_s;
        }

        int aux = n_bachelor - n_spinster;
        cout << "Case " << index << ": ";

        (aux<=0) ? cout << "0" << endl : cout << aux << " " << bachelor.top() << endl;

        index++;
    }
}