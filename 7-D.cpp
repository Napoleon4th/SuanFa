//
// Created on 2023/10/30.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int Avalues[n];
    int Bvalues[n];

    for (int i = 0; i < n; i++) {
        cin >> Avalues[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> Bvalues[i];
    }

    sort(Avalues, Avalues + n, greater<int>());
    sort(Bvalues, Bvalues + n, greater<int>());

    long long A_score = 0;
    long long B_score = 0;
    int turn = 0;

    for (int i = 0; i < n; i++) {
        if (turn == 0) {
            A_score += Avalues[i];
        } else {
            B_score += Bvalues[i];
        }
        turn = 1 - turn;
    }

    if (A_score > B_score) {
        cout << 1 << endl;
    } else if (A_score < B_score) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}