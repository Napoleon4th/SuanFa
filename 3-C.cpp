//
// Created on 2023/10/2.
//
#include <iostream>
#include <string>
using namespace std;
string remove(string n, int k) {
    int nLen = n.length();
    string result = "";
    for (char digit : n) {
        while (k > 0 && !result.empty() && result.back() > digit) {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }
    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }
    int nonZeroIdx = 0;
    while (nonZeroIdx < result.length() && result[nonZeroIdx] == '0') {
        nonZeroIdx++;
    }
    if (nonZeroIdx == result.length()) {
        return "0";
    } else {
        return result.substr(nonZeroIdx);
    }
}
int main() {
    string n;
    int k;
    cin >> n >> k;
    string result = remove(n, k);
    cout << result << endl;
    return 0;
}
