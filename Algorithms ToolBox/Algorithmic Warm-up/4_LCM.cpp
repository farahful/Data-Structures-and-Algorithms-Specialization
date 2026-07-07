#include <iostream>

using namespace std;

//  Time: O(log n)   |   Space: O(1)

long long gcd(long long a, long long b);
long long lcm(int a, int b);

int main() {
    int a, b;
    cin >> a >> b;

    cout << lcm(a, b) << endl;
}

long long gcd(long long a, long long b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(int a, int b) {
    return ((long long)a * b) / gcd(a, b);
}
