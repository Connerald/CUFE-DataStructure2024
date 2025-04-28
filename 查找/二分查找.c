#include <stdio.h>

// 二分查找函数
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 检查中间元素
        if (arr[mid] == target) {
            return mid;
        }

        // 如果目标值大于中间元素，忽略左半部分
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // 如果目标值小于中间元素，忽略右半部分
        else {
            right = mid - 1;
        }
    }

    // 如果找不到目标值，返回 -1
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("元素在数组中的索引为: %d\n", result);
    } else {
        printf("数组中没有找到该元素\n");
    }

    return 0;
}