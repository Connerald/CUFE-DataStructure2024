#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 函数原型声明
void insertNode(Node** head, int data);
void printList(Node* head);
void freeList(Node* head);
Node* createNode(int data);
Node* createList(void);

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* nodeToFree;
    while (head != NULL) {
        nodeToFree = head;
        head = head->next;
        free(nodeToFree);
    }
}

// 插入新节点到链表末尾
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 建立链表
Node* createList() {
    Node* head = NULL;
    int inputValue;

    printf("请输入整数，输入单个节点后按enter继续输入，输入-1结束：\n");
    while (1) {
        scanf("%d", &inputValue);
        if (inputValue == -1) {
            break;
        }
        insertNode(&head, inputValue);
    }
    return head;
}

int main() {
    Node* head = createList();

    printf("建立的链表内容如下：\n");
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}
