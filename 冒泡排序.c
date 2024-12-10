#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                /*
                交换 arr[j] 和 arr[j+1]
                这里如果是arr[j] < arr[j+1]就是从大到小排序
                */
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("排序前的数组: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("排序后的数组: \n");
    printArray(arr, n);
    return 0;
}