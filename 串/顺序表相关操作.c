#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int size;
} SeqList;

// 初始化，返回指针类型为顺序表的指针。
SeqList* initSeqList() {
    SeqList *list = (SeqList*)malloc(sizeof(SeqList));
    list->size = 0;
    return list;
}

// 添加元素到顺序表
void addNode(SeqList *list, int element) {
    if (list->size < MAXSIZE) {
        list->data[list->size] = element;
        list->size++;
    } else {
        printf("顺序表已满，无法添加元素。\n");
    }
}

// 在第i个位置插入元素到顺序表
void insertNode(SeqList *list, int i, int x) {
    if (i < 0 || i > list->size) {
        printf("插入位置无效。\n");
        return;
    }
    if (list->size >= MAXSIZE) {
        printf("顺序表已满，无法插入元素。\n");
        return;
    }
    for (int j = list->size; j > i - 1; j--) {
        list->data[j] = list->data[j - 1];
    }
    list->data[i - 1] = x;
    list->size++;
}

// 删除第i个位置的元素
void deleteNode(SeqList *list, int i) {
    if (i < 0 || i >= list->size) {
        printf("删除位置无效。\n");
        return;
    }
    for (int j = i - 1; j < list->size - 1; j++) {
        list->data[j] = list->data[j + 1];
    }
    list->size--;
}

// 打印顺序表
void printSeqList(SeqList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 释放顺序表
void freeSeqList(SeqList *list) {
    free(list);
}

int main() {
    SeqList *list = initSeqList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    insertNode(list, 1, 4); // 把元素4插入到第i个位置
    printSeqList(list);
    deleteNode(list, 2); // 删除第i个位置的元素
    printSeqList(list);
    freeSeqList(list);
    return 0;
}