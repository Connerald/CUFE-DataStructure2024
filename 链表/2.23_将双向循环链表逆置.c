#include <stdio.h>
#include <stdlib.h>

// 定义双循环链表的节点结构
typedef struct DListNode {
    int data;
    struct DListNode* prev;
    struct DListNode* next;
} DListNode;

// 创建一个新节点
DListNode* createNode(int data) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

// 查找值为keyx的节点
DListNode* search(DListNode* head, int keyx) {
    DListNode* current = head;
    if (head == NULL) return NULL;
    do {
        if (current->data == keyx) return current;
        current = current->next;
    } while (current != head);
    return NULL;
}

// 在值为keyx的节点后插入新节点
void insertAfter(DListNode** head, int keyx, int data) {
    DListNode* keyNode = search(*head, keyx);
    if (keyNode == NULL) {
        printf("节点%d未找到\n", keyx);
        return;
    }
    DListNode* newNode = createNode(data);
    newNode->next = keyNode->next;
    newNode->prev = keyNode;
    keyNode->next->prev = newNode;
    keyNode->next = newNode;
}

// 在值为keyx的节点前插入新节点
void insertBefore(DListNode** head, int keyx, int data) {
    DListNode* keyNode = search(*head, keyx);
    if (keyNode == NULL) {
        printf("节点%d未找到\n", keyx);
        return;
    }
    DListNode* newNode = createNode(data);
    newNode->next = keyNode;
    newNode->prev = keyNode->prev;
    keyNode->prev->next = newNode;
    keyNode->prev = newNode;
    if (keyNode == *head) {
        *head = newNode;
    }
}

// 删除值为keyx的节点
void deleteNode(DListNode** head, int keyx) {
    DListNode* keyNode = search(*head, keyx);
    if (keyNode == NULL) {
        printf("节点%d未找到\n", keyx);
        return;
    }
    if (keyNode->next == keyNode) {
        free(keyNode);
        *head = NULL;
        return;
    }
    keyNode->prev->next = keyNode->next;
    keyNode->next->prev = keyNode->prev;
    if (keyNode == *head) {
        *head = keyNode->next;
    }
    free(keyNode);
}

// 打印双循环链表
void printList(DListNode* head) {
    if (head == NULL) {
        printf("链表为空\n");
        return;
    }
    DListNode* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// 从输入建立链表
void createListFromInput(DListNode** head) {
    int data;
    printf("请输入节点值，以-1结束：\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        if (*head == NULL) {
            *head = createNode(data);
        } else {
            insertAfter(head, (*head)->prev->data, data);
        }
    }
}

// 逆置双循环链表
void reverseList(DListNode* head) {
    if (head == NULL) return;
    DListNode* current = head;
    DListNode* temp = NULL;
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != head);
}

int main() {
    DListNode* head = NULL;
    createListFromInput(&head);
    printf("原链表: ");
    printList(head);

    reverseList(head);
    printf("逆置后的链表: ");
    printList(head);

    return 0;
}