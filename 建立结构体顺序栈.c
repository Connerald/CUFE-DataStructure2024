#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义栈的结构体
typedef struct {
    int* elements;
    int top;
    int maxSize;
} Stack;

// 初始化栈
Stack* createStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    stack->elements = (int*)malloc(maxSize * sizeof(int));
    if (stack->elements == NULL) {
        printf("内存分配失败\n");
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->maxSize = maxSize;
    return stack;
}

// 释放栈的内存
void freeStack(Stack* stack) {
    if (stack != NULL) {
        free(stack->elements);
        free(stack);
    }
}

// 检查栈是否为空
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 检查栈是否已满
bool isFull(Stack* stack) {
    return stack->top == stack->maxSize - 1;
}

// 入栈操作
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    stack->elements[++stack->top] = element;
}

// 出栈操作
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        return -1; // 返回一个错误值
    }
    return stack->elements[stack->top--];
}

// 获取栈顶元素
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法获取栈顶元素\n");
        return -1; // 返回一个错误值
    }
    return stack->elements[stack->top];
}

// 打印栈中的所有元素
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        return;
    }
    printf("栈中的元素：\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printStack(stack);

    int poppedElement = pop(stack);
    printf("出栈元素：%d\n", poppedElement);

    printStack(stack);

    int topElement = peek(stack);
    printf("栈顶元素：%d\n", topElement);

    freeStack(stack);

    return 0;
}