#include <iostream>

using namespace std;

//  using Euclidean Algorithm
//  Time: O(log n)   |   Space: O(log n)

int gcd(int a, int b);

int main() {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }

    return gcd(b, a % b);
}
