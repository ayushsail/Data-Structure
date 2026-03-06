#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int rear;
    int front;
    int *q;
};

void create(struct queue *qt){
    printf("Enter the size : ");
    scanf("%d", &qt->size);
    qt->front = -1;
    qt->rear = -1;
    qt->q = (int *) malloc (qt->size*sizeof(int));
}

void enqueue (struct queue *qt, int x) {
    if(qt->rear == qt->size-1){
        printf("Queue Overflow\n");
    }
    else {
        qt->rear++;
        qt->q[qt->rear] = x;
    }
}

void display (struct queue *qt) {
    int i;
    printf("The elements are : ");
    for(i= qt->front + 1;i<=qt->rear;i++){
        printf("%d ", qt->q[i]);
    }
    printf("\n");
}

int dequeue (struct queue *qt) {
    int x = -1;
    if(qt->front == qt->rear) {
        printf("Queue Underflow\n");
    }
    else{
        qt->front++;
        qt->q[qt->front] = x;
        return x;
    }
}

int peek (struct queue *qt) {
    int x = -1;
    if(qt->front == qt->rear) {
        printf("Queue Underflow\n");
    }
    else{
        qt->q[qt->front+1];
    }
}

int isEmpty (struct queue *qt) {
    if(qt->front == qt->rear) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (struct queue *qt) {
    if(qt->rear == qt->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    struct queue qt;
    create(&qt);
    enqueue(&qt,10);
    enqueue(&qt,20);
    enqueue(&qt,30);
    enqueue(&qt,40);
    enqueue(&qt,50);
    display(&qt);
    printf("The front element is %d\n", peek(&qt));
    printf("Dequeued %d\n", dequeue(&qt));
    printf("Dequeued %d\n", dequeue(&qt));
    printf("Dequeued %d\n", dequeue(&qt));
    printf("Dequeued %d\n", dequeue(&qt));
    printf("The front element is %d\n", peek(&qt));
    display(&qt);

}