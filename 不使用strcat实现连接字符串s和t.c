#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_concat(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    // 分配足够的空间存储连接后的字符串
    char *result = (char *)malloc(len_s + len_t + 1);
    if (result == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }

    // 复制s到result
    int i = 0;
    for (i = 0; i < len_s; i++) {
        result[i] = s[i];
    }

    // 复制t到result
    int j = 0;
    for (j = 0; j < len_t; j++) {
        result[i + j] = t[j];
    }

    // 添加字符串结束符
    result[i + j] = '\0';

    return result;
}

int main() {
    char s[100], t[100];

    // 输入两个字符串
    printf("请输入第一个字符串 s: ");
    fgets(s, sizeof(s), stdin);
    printf("请输入第二个字符串 t: ");
    fgets(t, sizeof(t), stdin);

    // 去除输入字符串末尾的换行符
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
    if (t[strlen(t) - 1] == '\n') t[strlen(t) - 1] = '\0';

    // 调用string_concat函数并获取连接后的字符串
    char *result = string_concat(s, t);

    // 输出连接后的字符串
    printf("连接后的字符串是: %s\n", result);

    // 释放动态分配的内存
    free(result);

    return 0;
}
