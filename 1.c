#include <stdio.h>

int main(void){

    int n_cases, x, y;
    scanf("%d", &n_cases);

    for(int i = 0; i < n_cases; i++){
        scanf("%d %d", &x, &y);

        if((x+y*2)%2 == 0 && (y%2==0 || x>0))
            printf("YES\n");
        else 
            printf("NO\n");
    }
}