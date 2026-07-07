#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//  Time: O(n log n)   |   Space: O(n)


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n);
    for(int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    sort(segments.begin(), segments.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int numOfPoints = 0;
    vector<int> points;
    int point = -1;
    for(pair<int, int> segment: segments) {
        if(point == -1 || !(point >= segment.first && point <= segment.second)) {
            point = segment.second;
            numOfPoints++;
            points.push_back(point);
        }
    }
    
    cout << numOfPoints << endl;
    for(int p: points) {
        cout << p << " ";
    }
}