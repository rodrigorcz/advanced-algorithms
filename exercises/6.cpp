#include <iostream>
#include <queue>


using namespace std;

int main(int argc, char * argv[]){
    int n_cases;
    cin >> n_cases;

    for(int i = 0; i<n_cases; i++){
        int n, m;
        cin >> n >> m;
        char wall[n][m];

        int left = -1, right = m;
        int top = n;

        for(int j = 0; j<n; j++){
            string v;
            cin >> v;

            for(int k = 0; k<m; k++){
                wall[j][k] = v[k];

                if (wall[j][k] == 'B'){
                    if(top > j)
                        top = j;

                    if(left == -1 || left > k)
                        left = k;

                    if(right == m || right < k)
                        right = k;
                }
            }
        }

        int colun = 0;
        (left == -1 || right == -1) ? left = right = 0 : colun = 1;
        
        colun = colun + (right - left);

        int line = n-top;
        cout << line << " " << colun << endl;
    }
}
