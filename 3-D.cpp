//
// Created on 2023/10/2.
//
#include <iostream>
#include <string>
using namespace std;
bool canInterleave(const string& s, const string& t, const string& r, int i, int j, int k) {
    if (i == s.length() && j == t.length() && k == r.length()) {
        return true;
    }
    bool valid = false;

    if (i < s.length() && s[i] == r[k]) {
        valid = valid || canInterleave(s, t, r, i + 1, j, k + 1);
    }
    if (j < t.length() && t[j] == r[k]) {
        valid = valid || canInterleave(s, t, r, i, j + 1, k + 1);
    }
    return valid;
}
int main() {
    string s, t, r;
    cin >> s >> t >> r;
    if (canInterleave(s, t, r, 0, 0, 0)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}