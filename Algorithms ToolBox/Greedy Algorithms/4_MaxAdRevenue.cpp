#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

//  Time: O(n log n)   |   Space: O(n)


int main() {
    int n;
    cin >> n;
    vector<ll> profits(n);
    vector<ll> averageClicks(n);

    for(int i = 0; i < n; i++) {
        cin >> profits[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> averageClicks[i];
    }
    sort(profits.begin(), profits.end());
    sort(averageClicks.begin(), averageClicks.end());

    ll maxRevenue = 0;
    for(int i = 0; i < n; i++) {
        maxRevenue += profits[i] * averageClicks[i];
    }

    cout << maxRevenue << endl;
}