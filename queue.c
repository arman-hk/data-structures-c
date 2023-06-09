// queue structure based on FIFO
#include <stdio.h>

#define MAX_SIZE 100

typedef struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue* queue, int data) {
    if (queue -> rear == MAX_SIZE - 1) {
        printf("Overflow\n");
        return;
    }
    if (queue -> front == -1 && queue -> rear == -1) {
        queue -> front = queue -> rear = 0;
    } else {
        queue -> rear++;
    }
    queue -> data[queue -> rear] = data;
}

int dequeue(Queue* queue) {
    if (queue -> front == -1) {
        printf("Underflow\n");
        return -1;
    }
    int item = queue -> data[queue -> front];
    if (queue -> front == queue -> rear) {
        queue -> front = queue -> rear = -1;
    } else {
        queue -> front++;
    }
    return item;
}


int main() {
    // init an empty queue
    Queue queue;
    queue.front = queue.rear = -1;

    // enqueue elements
    enqueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 15);

    // dequeue elements and print
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));
    printf("%d\n", dequeue(&queue));

    return 0;
}
