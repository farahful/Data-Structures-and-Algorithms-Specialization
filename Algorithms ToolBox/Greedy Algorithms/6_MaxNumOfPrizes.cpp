#include <iostream>
#include <vector>

using namespace std;

//  Time: O(sqrt(n))   |   Space: O(sqrt(n))


int main() {
    int n;
    cin >> n;

    int numOfPrizes = 0;
    vector<int> prizeAmounts;
    int remaining = n;
    for(int i = 1; i <= n; i++) {
        if(remaining - i > i) {
            numOfPrizes++;
            prizeAmounts.push_back(i);
            remaining -= i;
        } else {
            numOfPrizes++;
            prizeAmounts.push_back(remaining);
            break;
        }
    }

    cout << numOfPrizes << endl;
    for(int amount: prizeAmounts) {
        cout << amount << " "; 
    }
}