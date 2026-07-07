#include <iostream>
#include <vector>

using namespace std;

//  Time: O(n)   |   Space: O(n)


int main() {
    int destination, tankRange, stationCount;
    cin >> destination >> tankRange >> stationCount;
    vector<int> stations(stationCount + 2);

    stations[0] = 0;
    for(int i = 1; i <= stationCount; i++) {
        cin >> stations[i];
    }
    stations[stationCount + 1] = destination; // all stops vector

    int curr = stations.front();
    int refills = 0; 
    int next = 1;

    if(stationCount == 0 && destination <= tankRange) {
        cout << 0 << endl;
        return 0;
    }

    while(curr != destination) {
        int reachable = curr;
        if(stations[next] - curr > tankRange) {
            cout << -1 << endl;
            return 0;
        }

        while(next < stations.size()) {
            if(stations[next] - curr <= tankRange) {
                reachable = stations[next];
                next++;
            } else {
                break;
            }
        }

        curr = reachable;
        if(curr != destination) {
            refills++;
        }
    }
    
    cout << refills << endl;
}