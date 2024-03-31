#include <iostream>
#include <string>
#include <queue>

using namespace std;

char elements[4] = {'A', 'C', 'G', 'T'};

int num_changes(string str1, string str2, int n){
    int diff = 0;

    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) 
            diff++;
    }

    return diff;
}

void backtracking(string dna_of, string dna_mut, int index, int n, int k, int changes, queue<string>&mut){

    if(index == n){
        mut.push(dna_mut);
        return;
    }else if (index < n){
        for(int i = 0; i<4; i++){
            char letter = elements[i];
            dna_mut[index] = letter;
            changes = num_changes(dna_of, dna_mut, n);

            if(changes <= k)
                backtracking(dna_of, dna_mut, index+1, n, k, changes, mut);
        }
    }
}

int main(int argc, char * argv[]){
    int n_cases;
    cin >> n_cases;

    for(int i = 0; i<n_cases; i++){
        int n, k;
        cin >> n >> k;

        string dna; 
        cin >> dna;

        queue<string> mut;
        backtracking(dna, dna, 0, n, k, 0, mut);

        cout << mut.size() << endl;

        while(mut.size() > 0){
            cout << mut.front() << endl;
            mut.pop();
        }
    }
}