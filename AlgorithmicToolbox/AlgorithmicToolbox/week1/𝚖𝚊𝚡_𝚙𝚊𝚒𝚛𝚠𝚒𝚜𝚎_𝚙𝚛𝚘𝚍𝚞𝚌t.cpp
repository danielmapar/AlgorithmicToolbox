//
//  𝚖𝚊𝚡_𝚙𝚊𝚒𝚛𝚠𝚒𝚜𝚎_𝚙𝚛𝚘𝚍𝚞𝚌t.cpp
//  AlgorithmicToolbox
//
//  Created by Daniel Parreira on 2016-09-10.
//  Copyright © 2016 Daniel Parreira. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long result = 0;
    unsigned long n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (numbers[i] * numbers[j] > result) {
                result = numbers[i] * numbers[j];
            }
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {

    long n = numbers.size();

    int max_index1 = 0;
    for (int i = 0; i+1 < n; ++i) {
        if (numbers[max_index1] <= numbers[i+1]) {
            max_index1 = i+1;
        }
    }

    int max_index2 = (max_index1==0 ? 1 : 0);
    for (int i = 0; i+1 < n; ++i) {
        if (i+1 == max_index1) {
            continue;
        }
        else if (numbers[max_index2] <= numbers[i+1]) {
            max_index2 = i+1;
        }
    }
    
    // little hack to pass courseras test case system
    // works fine on clang llvm
    return static_cast<long long>(numbers[max_index1]) * numbers[max_index2];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    //long long result1 = MaxPairwiseProduct(numbers);
    long long result2 = MaxPairwiseProductFast(numbers);
    cout << result2;
    // cout << result2 << "\n" << result2 << endl;
    /*
    while (true) {
        int n = rand() % 10 + 2;
        cerr << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i) {
            cerr << a[i] << ' ';
        }
        cerr << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2) {
            cerr << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else {
            cerr << "OK\n";
        }
    }*/

    return 0;
}

