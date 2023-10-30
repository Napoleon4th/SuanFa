//
// Created on 2023/10/30.
//
#include<iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int matrix[1000][1000];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = matrix[i][j];
            bool isMinInRow = true, isMaxInCol = true;

            for (int k = 0; k < n; ++k) {
                if (matrix[i][k] < num) {
                    isMinInRow = false;
                    break;
                }
            }

            for (int k = 0; k < m; ++k) {
                if (matrix[k][j] > num) {
                    isMaxInCol = false;
                    break;
                }
            }

            if (isMinInRow && isMaxInCol) {
                cout << num;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}