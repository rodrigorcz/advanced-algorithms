#include <iostream>

using namespace std;

// euclid's algorithm MDC(b,a%b)
string mdc(string s1, string s2){
   
    if (s1.length() < s2.length()){
        return mdc(s2, s1);

    }else if(s1.find(s2) != 0){
        return "";

    }else if (s2 == ""){
        return s1;

    }else{
        return mdc(s1.substr(s2.length()), s2);
    }
}
 
int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout << mdc(s1, s2) << endl;

    return 0;
}