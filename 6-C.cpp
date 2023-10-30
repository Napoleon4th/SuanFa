//
// Created by 范佳林 on 2023/10/30.
//
#include <stdio.h>
#include <algorithm>


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++; // 增加索引
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex == k)
            return arr[partitionIndex];
        else if (partitionIndex > k)
            return quickSelect(arr, low, partitionIndex - 1, k);
        else
            return quickSelect(arr, partitionIndex + 1, high, k);
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", quickSelect(arr, 0, n - 1, k - 1));
    return 0;
}