#include <iostream>
#include <vector>

using namespace std;

//  Sum of Fib(n)^2 = Fib(n) * F(n + 1)
//  Time: O(1)   |   Space: O(1)

int modFib(long long n, int m);
int sumSquareLastDigit(long long n);

int main() {
    long long n;
    cin >> n;

    cout << sumSquareLastDigit(n) << endl;
}

int modFib(long long n, int m) {
    if(n <= 1) {
        return n % m;
    }
    vector<int> sequence = {0, 1};
    long long prev1 = 1;
    long long prev2 = 0;

    int period = 0;
    while(true) {
        int fib = (prev1 + prev2) % m;
        prev2 = prev1;
        prev1 = fib;
        period++;

        if(prev1 == 1 && prev2 == 0) {
            break;
        }
        sequence.push_back(fib);
    }

    n %= period;
    return sequence[n];
}

int sumSquareLastDigit(long long n) {
    return (modFib(n, 10) * modFib(n + 1, 10)) % 10;
}