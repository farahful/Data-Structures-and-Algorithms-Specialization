#include <iostream>
#include <vector>

using namespace std;

//  using Pisano Algorithm
//  Time: O(m^2)   |   Space: O(m^2)

long long modFib(long long n, int m);

int main() {
    long long n;
    int m;
    cin >> n >> m;

    cout << modFib(n, m) << endl;
}

long long modFib(long long n, int m) {
    if(n <= 1) {
        return n % m;
    }

    vector<long long> sequence = {0, 1};
    long long prev1 = 1;
    long long prev2 = 0;

    int period = 0;
    while(true) {
        long long next = (prev1 + prev2) % m;
        prev2 = prev1;
        prev1 = next;
        period++;
        
        if(prev1 == 1 && prev2 == 0) {
            break;
        }
        sequence.push_back(next);
    }

    n %= period;
    return sequence[n];
}