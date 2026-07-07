#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//  Time: O(n log n)   |   Space: O(n)


int main() {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for(string& number: numbers) {
        cin >> number;
    }

    sort(numbers.begin(), numbers.end(), [](string a, string b) {
        return a + b > b + a;
    });
    string salary = "";
    for(string number : numbers) {
        salary += number;
    }

    cout << salary << endl;
}