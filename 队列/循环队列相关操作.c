#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// 初始化队列
void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = 0;
}

// 检查队列是否为空
int isEmpty(CircularQueue *q) {
    return q->front == q->rear;
}

// 检查队列是否已满
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// 入队操作
int enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return -1;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
    return 0;
}

// 出队操作
int dequeue(CircularQueue *q, int *value) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return 0;
}

// 打印队列
void printQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printQueue(&q);

    int value;
    dequeue(&q, &value);
    printf("Dequeued: %d\n", value);
    printQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 6);
    printQueue(&q);

    return 0;
}