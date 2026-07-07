#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Optimal Solution O(n)

int main() {
    int n;
    cin >> n;

    vector<int> parent(n);
    for(int i = 0; i < n; i++) {
        cin >> parent[i];
    }
    vector<int> height(n, 0);
    int max_height = 0;
    for(int i = 0; i < n; i++) {
        int curr = i;
        int curr_height = 1;
        while(parent[curr] != -1 && height[curr] == 0) {
            curr = parent[curr];
            curr_height++;
        }
        if(height[curr] != 0) {
            curr_height = height[curr] - 1;
        }
        height[i] = curr_height;
        max_height = max(max_height, curr_height);
    }
    cout << max_height << endl;
    return 0;
}

/* Naive Solution O(n^2)

int main() {
    int n;
    cin >> n;

    vector<int> parent(n);
    for(int i = 0; i < n; i++) {
        cin >> parent[i];
    }

    int max_height = 0;
    for(int i = 0; i < n; i++) {
        int curr = i;
        int curr_height = 1;
        while(parent[curr] != -1) {
            curr = parent[curr];
            curr_height++;
        }
        max_height = max(max_height, curr_height);
    }

    cout << max_height << endl;
    return 0;
}

*/