//
//  gcd.cpp
//  AlgorithmicToolbox
//
//  Created by Daniel Parreira on 2016-09-18.
//  Copyright © 2016 Daniel Parreira. All rights reserved.
//

#include <iostream>

using namespace std;

int EuclidGCD(int a, int b);

int main(void) {
    int a, b;
    
    cin >> a >> b;
    cout << EuclidGCD(a, b) << endl;
    
    return 0;
}


int EuclidGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    // a` is the remainder (resto)
    // quotient (resultado da divisao)
    int aPrime = a % b;
    cout << "A: " << b << endl;
    cout << "B: " << aPrime << endl;

    return EuclidGCD(b, aPrime);
}

