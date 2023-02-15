#include <iostream>
using namespace std;

bool is_divisible(long long num, int n) {
    int divisors = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisors++;
        }
    }
    return divisors == n;
}

int main() {
    int n;
    cin >> n;
    long long num = 1;
    while (!is_divisible(num,n)) {
        num++;
    }
    cout << num << endl;
    return 0;
}

