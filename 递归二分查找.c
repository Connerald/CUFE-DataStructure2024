#include <stdio.h>

// 递归二分查找函数
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // 检查中间元素
        if (arr[mid] == target) {
            return mid;
        }

        // 如果目标值大于中间元素，递归右半部分
        if (arr[mid] < target) {
            return recursiveBinarySearch(arr, mid + 1, right, target);
        }
        // 如果目标值小于中间元素，递归左半部分
        else {
            return recursiveBinarySearch(arr, left, mid - 1, target);
        }
    }

    // 如果找不到目标值，返回 -1
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = recursiveBinarySearch(arr, 0, size - 1, target);

    if (result != -1) {
        printf("元素在数组中的索引为: %d\n", result);
    } else {
        printf("数组中没有找到该元素\n");
    }

    return 0;
}