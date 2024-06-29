#include <iostream>
#include <vector>
#include <string>

using namespace std;

void kmp_pre_process(vector<int>& b, string pat, int tam){
    int i = 0;
    int j = -1;
    b[0] = -1;

    while(i < tam){
        while(j >= 0 && pat[i] != pat[j])
            j = b[j];
        
        i++; 
        j++;
        b[i] = j;
    }
}

int kmp_search(vector<int> b, string pat, string txt){
    int i = 0, j = 0;
    int count = 0;

    while(i<txt.size()){
        while(j>=0 && txt[i] != pat[j])
            j = b[j];
        
        i++;
        j++;
        if(j == pat.size()){
            count++;
            j = b[j];
        }
    }

    return count;
}

int main(){
    string txt, pat;

    cin >> txt >> pat;

	vector<int> b(pat.size()+1);

    kmp_pre_process(b, pat, pat.size());

    int c = kmp_search(b, pat, txt);

    cout << c << endl;

    return 0;
}