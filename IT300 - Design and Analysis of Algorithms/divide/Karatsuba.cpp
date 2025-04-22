#include<iostream>
#include<string>
#include<cmath>

using namespace std;




int makeEqualLength(string &str1, string &str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    } else if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1; 
}


string addStrings(string first, string second) {
    string result;

    
    int length = makeEqualLength(first, second);
    int carry = 0;

    
    for (int i = length - 1; i >= 0; i--) {
        int firstDigit = first.at(i) - '0';
        int secondDigit = second.at(i) - '0';

        int sum = firstDigit + secondDigit + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }

    
    if (carry)
        result = '1' + result;

    return result;
}


int multiplySingleDigit(string a, string b) {
    return (a[0] - '0') * (b[0] - '0');
}



long long multiply(string X, string Y) {
    
    
    int n = makeEqualLength(X, Y);

    
    if (n == 0)
        return 0;
    if (n == 1)
        return multiplySingleDigit(X, Y);

    int fh = n / 2; 
    int sh = (n - fh); 

    
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);

    
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    
    long long P1 = multiply(Xl, Yl);
    long long P2 = multiply(Xr, Yr);
    long long P3 = multiply(addStrings(Xl, Xr), addStrings(Yl, Yr));

    
    return P1 * pow(10, 2 * sh) + (P3 - P1 - P2) * pow(10, sh) + P2;
}


int main() {
    cout << multiply("1234", "5678") << endl;
    cout << multiply("100", "200") << endl;
    cout << multiply("9", "9") << endl;
    cout << multiply("15", "25") << endl;
    cout << multiply("0", "9876543210") << endl;
    cout << multiply("999", "999") << endl;
    cout << multiply("12", "34") << endl;

    return 0;
}
