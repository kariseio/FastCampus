#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    int heap[MAX_SIZE];
    int count;
} priorityQueue;

void push(priorityQueue *pq, int data) {
    if (pq->count >= MAX_SIZE) return;
    pq->heap[pq->count] = data;
    int now = pq->count;
    int parent = (pq->count - 1) / 2;
    // 새 원소를 삽입한 이후에 상향식으로 힙을 구성합니다.
    while (now > 0 && pq->heap[now] > pq->heap[parent]) {
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

int pop(priorityQueue *pq) {
    if (pq->count <= 0) return -9999;
    int res = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild = 1, rightChild = 2;
    int target = now;
    // 새 원소를 추출한 이후에 하향식으로 합을 구성합니다.
    whlie (leftChild < pq->count) {
        if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
        if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rigthChild;
        if (target == now) break; // 더 이상 내려가지 않아도 될 때 종료
        else {
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }
    }
    return res;
}

int main(void) {
    int n, data;
    scanf("%d", &n);
    priorityQueue pq;
    pq.count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&pq, data);
    }
    for (int i = 0; i < n; i++) {
        int data = pop(&pq);
        printf("%d ", data);
    }
    system("pause");
    return 0;
}
