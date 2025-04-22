#include<bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main(){
    int p,q;
    cout<<"Enter two primes p and q"<<endl;
    cin>>p>>q;
    int N=p*q;

    int phi_n=(p-1) * (q-1);

    int count=0;
    cout<<"Numbers relatively prime to N are: ";
    for(int i=1;i<N;i++){
        int x,y;
        if(extended_gcd(i,N,x,y) == 1){
            cout<<i<<" ";
            count++;
        }
    }

    cout << "\n\nComputed Values:";
    cout << "\nP = " << p << ", Q = " << q;
    cout << "\nN = " << N;
    cout << "\nϕ(N) = " << phi_n;
    cout << "\nCount of numbers relatively prime to " << N << " = " << count;
    
    if (count == phi_n) {
        std::cout << "\nVerification Successful: Count matches ϕ(N)\n";
    } else {
        std::cout << "\nVerification Failed: Count does not match ϕ(N)\n";
    }
    return 0;
}