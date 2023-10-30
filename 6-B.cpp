//
// Created on 2023/10/30.
//
#include<iostream>
using namespace std;

int islandPerimeter(int grid[100][100], int n, int m) {
    int perimeter = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == 1) {
                if(i == 0 || grid[i-1][j] == 0) perimeter++;
                if(j == 0 || grid[i][j-1] == 0) perimeter++;
                if(i == n-1 || grid[i+1][j] == 0) perimeter++;
                if(j == m-1 || grid[i][j+1] == 0) perimeter++;
            }
        }
    }

    return perimeter;
}

int main() {
    int n, m;
    cin >> n >> m;
    int grid[100][100];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    cout << islandPerimeter(grid, n, m) << endl;

    return 0;
}