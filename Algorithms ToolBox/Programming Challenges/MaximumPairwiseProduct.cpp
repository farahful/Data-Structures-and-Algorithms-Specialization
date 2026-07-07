#include <vector>
#include <iostream>

using namespace std;

long long MaximumPairwiseProduct(vector<int>& nums) {
    int maxIndex1 = -1;
    int maxIndex2 = -1;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        if(maxIndex1 == -1 || nums[i] > nums[maxIndex1]) {
            maxIndex1 = i;
        }
    }
    for(int j = 0; j < size; j++) {
        if( (maxIndex2 == -1 || nums[j] > nums[maxIndex2]) && j != maxIndex1) {
            maxIndex2 = j; 
        }
    }
    return ((long long)(nums[maxIndex1])) * nums[maxIndex2];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int element;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    long long result = MaximumPairwiseProduct(nums);
    cout << result;
}