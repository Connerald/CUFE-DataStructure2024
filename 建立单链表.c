#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体并使用 typedef 命名
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 建立链表
Node* createLinkedList() {
    Node* head = NULL;
    int input;

    printf("请输入整数，输入单个节点后按enter继续输入，输入-1结束：\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        insertNode(&head, input);
    }

    return head;
}

int main() {
    Node* head = createLinkedList();

    printf("建立的链表内容如下：\n");
    printList(head);

    // 释放链表内存
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
