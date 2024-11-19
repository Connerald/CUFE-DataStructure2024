#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 链表逆置函数
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;  // 保存下一个节点
        current->next = prev;  // 当前节点指向前一个节点
        prev = current;        // 更新 prev
        current = next;        // 移动到下一个节点
    }
    return prev; // prev 是新的头节点
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// 主函数
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原链表: ");
    printList(head);

    head = reverseList(head);

    printf("逆置后链表: ");
    printList(head);

    freeList(head); // 释放内存
    return 0;
}
