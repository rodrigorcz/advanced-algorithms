#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

    int cases, x, y;
    cin >> cases;

    for(int i = 0; i<cases; i++){

        cin >> x >> y;

        if((x+y*2)%2==0){
            if(y%2==0 || x>0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;   
        }else
            cout << "NO" << endl;
    }
}