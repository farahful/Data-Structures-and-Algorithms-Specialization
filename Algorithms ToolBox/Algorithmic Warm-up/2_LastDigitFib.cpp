#include <iostream>

using namespace std;

//  Time: O(n)   |   Space: O(1)

int LastDigitFib(int n);

int main() {
    int n;
    cin >> n;

    cout << LastDigitFib(n) << endl;
}

int LastDigitFib(int n) {
    if(n <= 1) {
        return n;
    }

    int result = 0;
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i++) {
        result = (prev1 + prev2) % 10;
        prev2 = prev1;
        prev1 = result;
    }
    
    return result;
}