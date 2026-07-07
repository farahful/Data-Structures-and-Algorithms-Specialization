#include <iostream>
#include <vector>

using namespace std;

//  Interval sum = prefix(end) - prefix(start - 1)
//  Time: O(1)   |   Space: O(1)

int modFib(long long n, int m);
int sumLastDigit(long long n);
int sumInterval(long long start, long long end);

int main() {
    long long start, end;
    cin >> start >> end;

    cout << sumInterval(start, end) << endl;
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

int sumLastDigit(long long n) {
    if(n < 0) {
        return 0;
    }
    return (modFib(n + 2, 10) + 9) % 10;
}

int sumInterval(long long start, long long end) {
    int endPrefix = sumLastDigit(end);
    int beforeStart = sumLastDigit(start - 1);
    
    return ((endPrefix - beforeStart) + 10) % 10; 
}