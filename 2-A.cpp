//
// Created on 2023/9/12.
//
#include <iostream>
#include <vector>
#include <stack>
#include<limits.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    int maxAz = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] < maxAz) {
            cout << "True" << endl;
            return 0;
        }
        while (!s.empty() && arr[i] > s.top()) {
            maxAz = max(maxAz, s.top());
            s.pop();
        }
        s.push(arr[i]);
    }
    cout << "False" << endl;
    return 0;
}