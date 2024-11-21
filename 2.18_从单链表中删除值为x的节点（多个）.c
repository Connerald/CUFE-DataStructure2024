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
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
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

// 从单链表中删除值为x的节点（多个）
void deleteNode(Node** head, int x) {
    Node* current = *head;
    Node* previous = NULL;
    Node* nodeToFree;
    while (current != NULL) {
        if (current->data == x) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            nodeToFree = current;
            current = current->next;
            free(nodeToFree);
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    Node* head = createList();

    printf("建立的链表内容如下：\n");
    printList(head);

    int x;
    printf("请输入要删除的节点值：");
    scanf("%d", &x);
    deleteNode(&head, x);

    printf("删除节点后链表内容如下：\n");
    printList(head);

    freeList(head);
    return 0;
}