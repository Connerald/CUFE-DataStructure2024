#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct Node {
    int data;               // 数据域
    struct Node *next;      // 指向下一个节点的指针
} Node;

// 定义线性表结构体
typedef struct {
    Node *head;             // 头指针
    int length;             // 线性表的长度
} LinkedList;

// 初始化线性表
void initList(LinkedList *list) {
    list->head = NULL;      // 初始为空表
    list->length = 0;
}

// 添加节点到线性表尾部
void append(LinkedList *list, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->length++;
}

// 在指定位置插入节点
void insert(LinkedList *list, int index, int value) {
    if (index < 0 || index > list->length) {
        printf("索引超出范围！\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *temp = list->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    list->length++;
}

// 删除指定位置的节点
void delete(LinkedList *list, int index) {
    if (index < 0 || index >= list->length) {
        printf("索引超出范围！\n");
        return;
    }

    Node *temp = list->head;
    if (index == 0) {
        list->head = temp->next;
        free(temp);
    } else {
        Node *prev;
        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    list->length--;
}

// 打印线性表
void printList(LinkedList list) {
    Node *temp = list.head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放线性表的内存
void freeList(LinkedList *list) {
    Node *temp;
    while (list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    list->length = 0;
}

int main() {
    LinkedList list;
    initList(&list);

    append(&list, 10);
    append(&list, 20);
    append(&list, 30);
    insert(&list, 1, 15);

    printf("线性表内容：\n");
    printList(list);

    delete(&list, 2);
    printf("删除节点后：\n");
    printList(list);

    freeList(&list);
    return 0;
}
