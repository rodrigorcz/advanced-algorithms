#include <iostream>
#include <cmath>
#include <iomanip>

#define ERRO 1e-9
#define NO -1

using namespace std;

double func(double x, double p, double q, double r, double s, double t, double u){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double find_x(double x1, double x2, double p, double q, double r, double s, double t, double u){
    double mid = (x2+x1)/2.0;
    double root = func(mid, p, q, r, s, t, u);

    double var1 = func(x1, p, q, r, s, t, u);
    double var2 = func(x2, p, q, r, s, t, u);

    if((x2 - x1) < ERRO)
        return mid;
        
    if(var1 * root <= 0)
        return find_x(x1, mid, p, q, r, s, t, u);
    else if(var2 * root <= 0)
        return find_x(mid, x2, p, q, r, s, t, u);
    
    return NO;
}

int main(){

    int n_cases;
    cin >> n_cases;

    for(int i = 0; i< n_cases; i++){
        double p, q, r, s, t, u;
        cin >> p >> q >> r >> s >> t >> u;

        double x = find_x(0, 1, p, q, r, s, t, u);

        if(x == NO)
            cout << "Sem solucao" << endl;
        else
            cout << fixed << setprecision(4) << x << endl;
        
    }
    return 0;
}
