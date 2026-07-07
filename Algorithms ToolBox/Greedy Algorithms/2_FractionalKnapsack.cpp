#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

//  Time: O(n log n)   |   Space: O(n)


bool compare(pair<int, int> a, pair<int, int> b) {
    return ((double)a.first / a.second) > ((double)b.first / b.second);
}

int main() {
    int num, capacity;
    cin >> num >> capacity;
    vector<pair <int, int>> items(num); // first = value, second = weight
    for(int i = 0; i < num; i++) {
        cin >> items[i].first >> items[i].second;
    }

    sort(items.begin(), items.end(), compare);
    int i = 0;
    double profit = 0;

    while(capacity > 0 && i < num) {
        double ratio = (double)items[i].first / items[i].second;
        if(capacity < items[i].second) {
            profit += capacity * ratio;
            break;
        }
        capacity -= items[i].second;
        profit += items[i].second * ratio;
        i++;
    }

    cout << fixed << setprecision(5) << profit << endl;
}