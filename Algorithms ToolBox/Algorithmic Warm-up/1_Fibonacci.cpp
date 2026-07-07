#include <iostream>

using namespace std;

//  Time: O(n)   |   Space: O(1)

long long Fib(int n);

int main() {
    int n;
    cin >> n;

    cout << Fib(n) << endl;
}

long long Fib(int n) {
    if(n <= 1) {
        return n;
    }

    long long result = 0;
    long long prev1 = 1;
    long long prev2 = 0;

    for(int i = 2; i <= n; i++) {
        result = prev1 + prev2;
        prev2 = prev1;
        prev1 = result;
    }

    return result;
}