#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;               // 数据域
    struct Node *next;      // 指向下一个节点的指针
} Node;

// 尾插法创建链表
Node* createListTailInsert() {
    Node *head = NULL;      // 初始化头指针
    Node *tail = NULL;      // 初始化尾指针
    int value;

    printf("请输入节点的值（-1 结束输入）：\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {  // 以 -1 结束输入
            break;
        }

        Node *newNode = (Node *)malloc(sizeof(Node)); // 为新节点分配内存
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // 第一个节点作为头节点
            tail = newNode;
        } else {
            tail->next = newNode;  // 将新节点连接到尾节点后
            tail = newNode;        // 更新尾节点
        }
    }
    return head;  // 返回链表头指针
}

// 打印链表
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *list = createListTailInsert();  // 尾插法创建链表
    printf("创建的链表内容：\n");
    printList(list);

    freeList(list);  // 释放链表的内存
    return 0;
}
