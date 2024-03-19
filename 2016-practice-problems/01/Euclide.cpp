//
// Created by konstantine on 3/14/24.
//

#include "Euclide.h"

int gcd(int a, int b);

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}

int gcd(int a, int b){
    if(b == 0)return a;

    return gcd(b, a % b);
}
