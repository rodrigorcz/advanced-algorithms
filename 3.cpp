#include <map>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
    
    int n_cases;
    cin >> n_cases;

    if( n_cases <= 100000 && n_cases >= 1){
        map<string, int> database;

        for(int i = 0; i<n_cases; i++){

            string name;
            cin >> name;

            int v = database[name];

            if(v == 0){
                database[name] = 1;
                cout << "OK" << endl;
            }else{
                string conc = name + to_string(v);
                database[name] = v+1;
                cout << conc << endl;
            }
        }
    }
}