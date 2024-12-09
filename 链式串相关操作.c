#include <stdio.h>
#include <stdlib.h>

// 定义链式串的节点结构
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 创建一个新节点
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 将字符串转换为链式串
Node* stringToLinkedList(const char* str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    Node* head = createNode(*str);
    Node* current = head;
    str++;

    while (*str != '\0') {
        current->next = createNode(*str);
        current = current->next;
        str++;
    }

    return head;
}

// 打印链式串
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放链式串的内存
void freeLinkedList(Node* head) {
    Node* current = head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// 连接两个链式串
Node* concatenateLinkedLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;

    return list1;
}

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    Node* linkedList1 = stringToLinkedList(str1);
    Node* linkedList2 = stringToLinkedList(str2);

    printf("链式串1内容: ");
    printLinkedList(linkedList1);

    printf("链式串2内容: ");
    printLinkedList(linkedList2);

    Node* concatenatedList = concatenateLinkedLists(linkedList1, linkedList2);
    printf("连接后的链式串内容: ");
    printLinkedList(concatenatedList);

    freeLinkedList(concatenatedList);
    return 0;
}