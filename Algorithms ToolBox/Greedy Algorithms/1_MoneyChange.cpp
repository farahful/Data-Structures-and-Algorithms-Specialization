#include <iostream>

using namespace std;

// Assume available change is 10, 5, 1
//  Time: O(1)   |   Space: O(1)


int main() {
    int money;
    cin >> money;
    
    int minCoins = 0;
    if(money >= 10) {
        minCoins += money / 10;
        money %= 10;
    }
    if(money >= 5) {
        minCoins += money / 5;
        money %= 5;
    }
    if(money > 0){
        minCoins += money;
    }
    
    cout << minCoins << endl;
}