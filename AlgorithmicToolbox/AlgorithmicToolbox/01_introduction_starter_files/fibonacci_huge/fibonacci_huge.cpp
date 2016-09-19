#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_fibonacci_huge_fast(int n, int m) {
    int first = 0, second = 1;
    int next = 0;
    
    if (n == 0 || n == 1) {
        next = n;
    }
    
    for (int i = 2; i <= n; i++) {
        next = (first + second) % m;
        first = second;
        second = next;
    }
    
    return next;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_fibonacci_huge_fast(n, 10) << '\n';
}
