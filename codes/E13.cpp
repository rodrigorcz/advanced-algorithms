#include <iostream>
#include <string.h>

using namespace std;

string shift(string a, int num){
    string shift = a;
    for (int i = 0 ; i < num ; i++)
        shift = shift + '0';
    return shift;
}
 
int controlSize(string &a, string &b){
    int len1 = a.size();
    int len2 = b.size();

    if (len1 < len2){
        for (int i = 0 ; i < len2 - len1 ; i++)
            a = '0' + a;
        return len2;
    }

    else if (len1 > len2){
        for (int i = 0 ; i < len1 - len2 ; i++)
            b = '0' + b;
    }

    return len1;
}

string addBinary(string a, string b){
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) 
            sum += a[i--] - '0';
        if (j >= 0) 
            sum += b[j--] - '0';

        carry = sum / 2;
        result = to_string(sum % 2) + result;
    }

    return result;
}

string subtractBinary(string a, string b) {
    int n = controlSize(a,b);

    string result = b;
    string aux;

    for(int i = 0; i < n; i++) {
        aux = aux + "0";
        (result[i] == '0')? result[i] = '1' : result[i] = '0';
    }

    aux[n-1] = '1';
    
    result = addBinary(result, aux);
    result = addBinary(a, result);
    result = result.substr(1, n);

    return result;
}

// Karatsuba algorithm 
string multiplyBinary(string a,  string b){
    int n = controlSize(a, b);
     
    if (n == 1) 
        return ((b[0]-'0' == 1) && (a[0]-'0' == 1)) ? "1" : "0";
     
    int fh = n/2; 
    int sh = (n-fh); 
     
    string al = a.substr(0, fh);
    string ar = a.substr(fh, sh);
     
    string bl = b.substr(0, fh);
    string br = b.substr(fh, sh);
     
    string pt1 = multiplyBinary(al, bl);
    string pt2 = multiplyBinary(ar, br);
    string pt3 = multiplyBinary(addBinary(al, ar), addBinary(bl, br));
     
    return addBinary(addBinary(shift(pt1, 2*(n-n/2)),pt2),shift(subtractBinary(pt3,addBinary(pt1,pt2)), n-(n/2)));
}

string removeZero(string str) {
    string aux = str;
    int flag = 0;

    while (!str.empty()) {
        if(str[0] == '1'){
            flag = 1;
            break;
        }
        str = str.substr(1);
    }

    if(flag == 1)
        return str;
    else
        return aux;
}

int main(void){
    int n;
    string a, b;

    cin >> n >> a >> b;

    string res = multiplyBinary(a,b);

    cout << removeZero(res);

    return 0;
}