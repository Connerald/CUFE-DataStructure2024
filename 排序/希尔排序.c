#include <stdio.h>

// 希尔排序函数
// 考试只要求概念 画线说明排序过程即可
void shellSort(int arr[], int n) {
    // 选择增量
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("排序后的数组: \n");
    printArray(arr, n);

    return 0;
}