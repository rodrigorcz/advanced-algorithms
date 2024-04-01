#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(int argc, char * argv[]){
    int n_inputs, n_cases;
    cin >> n_cases;

    for(int i = 1; i<=n_cases; i++){
        cin >> n_inputs;
        map<const string, const int> courses;

        for (int j = 0; j<n_inputs; j++){
            string word;
            int n_days;
            cin >> word >> n_days;

            courses.insert(make_pair(word, n_days));
        }

        int days;
        string search;
        cin >> days >> search;

        int key = courses[search];

        if(key<=days && key!=0)
            cout << "Case "<< i << ": Yesss" << endl;

        else if(key<=days + 5 && key!=0)
            cout << "Case "<< i << ": Late" << endl;
            
        else 
            cout << "Case " << i << ": Do your own homework!" << endl;

    }
}