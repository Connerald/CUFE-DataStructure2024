// 设两个栈共享一个数组空间S[m+1]，它们的栈底分别设在数组的两端，每个元素占用一个数组单元。
// 试为这两个公共栈设计初始化INITSTACK(S)、进栈PUSH(s,i,x)、出栈POP(S,i,x)和取栈顶元素GETTOP(S,i)算法，其中i=1,2用来指示栈的编号。
#include <stdio.h>
#include <stdlib.h>

#define M 100 // 假设数组的大小为100

typedef struct {
    int data[M + 1];
    int top1;
    int top2;
} SharedStack;

// 初始化栈
void INITSTACK(SharedStack *S) {
    S->top1 = -1;
    S->top2 = M;
}

// 进栈操作
int PUSH(SharedStack *S, int i, int x) {
    if (S->top1 + 1 == S->top2) {
        printf("栈满\n");
        return 0; // 栈满
    }
    if (i == 1) {
        S->data[++S->top1] = x;
    } else if (i == 2) {
        S->data[--S->top2] = x;
    } else {
        printf("栈编号错误\n");
        return 0; // 栈编号错误
    }
    return 1; // 进栈成功
}

// 出栈操作
int POP(SharedStack *S, int i, int *x) {
    if (i == 1) {
        if (S->top1 == -1) {
            printf("栈1空\n");
            return 0; // 栈1空
        }
        *x = S->data[S->top1--];
    } else if (i == 2) {
        if (S->top2 == M) {
            printf("栈2空\n");
            return 0; // 栈2空
        }
        *x = S->data[S->top2++];
    } else {
        printf("栈编号错误\n");
        return 0; // 栈编号错误
    }
    return 1; // 出栈成功
}

// 取栈顶元素
int GETTOP(SharedStack *S, int i, int *x) {
    if (i == 1) {
        if (S->top1 == -1) {
            printf("栈1空\n");
            return 0; // 栈1空
        }
        *x = S->data[S->top1];
    } else if (i == 2) {
        if (S->top2 == M) {
            printf("栈2空\n");
            return 0; // 栈2空
        }
        *x = S->data[S->top2];
    } else {
        printf("栈编号错误\n");
        return 0; // 栈编号错误
    }
    return 1; // 取栈顶元素成功
}

int main() {
    SharedStack S;
    INITSTACK(&S);

    // 测试代码
    PUSH(&S, 1, 10);
    PUSH(&S, 2, 20);
    int x;
    GETTOP(&S, 1, &x);
    printf("栈1顶元素: %d\n", x);
    GETTOP(&S, 2, &x);
    printf("栈2顶元素: %d\n", x);
    POP(&S, 1, &x);
    printf("从栈1弹出的元素: %d\n", x);
    POP(&S, 2, &x);
    printf("从栈2弹出的元素: %d\n", x);

    return 0;
}