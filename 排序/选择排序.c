#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // 一一移动数组的边界
    for (i = 0; i < n-1; i++) {
        // 找到剩余数组中的最小元素
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // 交换找到的最小元素和当前元素
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("排序后的数组: \n");
    printArray(arr, n);
    return 0;
}