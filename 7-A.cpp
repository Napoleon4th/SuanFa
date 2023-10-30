//
// Created on 2023/10/30.
//
#include <iostream>
#include <unordered_map>
using namespace std;

int subarraySum(int* nums, int n, int k) {
    unordered_map<int, int> preSum;
    preSum[0] = 1;

    int sum = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (preSum.find(sum - k) != preSum.end()) {
            count += preSum[sum - k];
        }
        preSum[sum]++;
    }

    return count;
}

int main() {
    int m;
    cin >> m;

    int* nums = new int[m];
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    cout << subarraySum(nums, m, k) << endl;

    delete[] nums;
    return 0;
}