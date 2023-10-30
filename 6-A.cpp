//
// Created on 2023/10/30.
//
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> cards;
    for (int i = 0; i < N; ++i) {
        int card;
        cin >> card;
        cards.push_back(card);
    }

    deque<int> result;
    for (int i = N - 1; i >= 0; --i) {
        if (!result.empty()) {
            int back = result.back();
            result.pop_back();
            result.push_front(back);
        }
        result.push_front(cards[i]);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i];
        if (i != N - 1) cout << " ";
    }

    return 0;
}