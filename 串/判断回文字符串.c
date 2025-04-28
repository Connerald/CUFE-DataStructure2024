#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 计算字符串长度的函数
int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// 判断一个字符串是否是回文字符串的函数
bool isPalindrome(char str[]) {
    int length = stringLength(str);
    int left = 0;
    int right = length - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    char str[100];

    // 输入一个字符串
    printf("请输入一个字符串: ");
    scanf("%s", str);

    // 判断并输出结果
    if (isPalindrome(str)) {
        printf("%s 是回文字符串。\n", str);
    } else {
        printf("%s 不是回文字符串。\n", str);
    }

    return 0;
}