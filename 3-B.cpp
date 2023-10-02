//
// Created on 2023/10/2.
//
#include <iostream>
#include <cstring>
using namespace std;
string multiplyStrings(string num1, string num2) {
    int m = num1.length();
    int n = num2.length();
    int resultSize = m + n;
    int result[resultSize];
    memset(result, 0, sizeof(result));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string resultStr = "";
    bool leadingZero = true;
    for (int i = 0; i < resultSize; i++) {
        if (result[i] != 0) {
            leadingZero = false;
        }
        if (!leadingZero) {
            resultStr += to_string(result[i]);
        }
    }
    return resultStr.empty() ? "0" : resultStr;
}
string multiplyWithPartition(int nums[], int n, int x) {
    string leftStr = "";
    string rightStr = "";
    for (int i = 0; i < n; i++) {
        if (nums[i] < x) {
            leftStr += to_string(nums[i]);
        } else {
            rightStr += to_string(nums[i]);
        }
    }
    if (leftStr.empty() || rightStr.empty()) {
        return "0";
    }
    string result = multiplyStrings(leftStr, rightStr);
    return result;
}
int main() {
    int n, x;
    cin >> n >> x;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    string result = multiplyWithPartition(nums, n, x);
    cout << result << endl;
    return 0;
}