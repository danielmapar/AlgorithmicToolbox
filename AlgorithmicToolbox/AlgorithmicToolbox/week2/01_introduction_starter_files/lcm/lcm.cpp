#include <iostream>

long long EuclidGCD(long long a, long long b) {
    if (b == 0)
        return a;
    
    return EuclidGCD(b, a % b);
}

long long LCM(long long a, long long b) {
    return (a*b)/EuclidGCD(a, b);
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << LCM(a, b) << std::endl;
  return 0;
}
