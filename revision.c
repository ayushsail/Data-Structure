#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *s;
};

void create (struct stack *st) {
    printf("Enter the size : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *) malloc (st->size*sizeof(int));
}

void display (struct stack *st) {
    int i;
    printf("The elements are : ");
    for (i=0; i<=st->top; i++){
        printf("%d ", st->s[i]);
    }
    printf("\n");
}

void push (struct stack *st, int x) {
    if (st->top == st->size-1) {
        printf("Overflow\n");
    }
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop (struct stack *st) {
    int x = -1;
    if (st->top == -1) {
        printf("Underflow\n");
    }
    else {
        x = st->s[st->top--];
    }
    return x;
}

int peektop (struct stack *st){
    int x = -1;
    if (st->top == -1) {
        printf("Underflow\n");
    }
    else {
        x = st->s[st->top];
    }
    return x;
}

int peek (struct stack *st, int position) {
    int x = -1;
    if (st->top == -1) {
        printf("Underflow\n");
    }
    if ( position <=0 || position > st->top+1) {
        printf("Invalid position\n");
    }
    else {
        x = st->s[position - 1];
        return x;
    }

}

int isEmpty (struct stack *st) {
    if (st->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (struct stack *st) {
    if (st->top == st->size - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    display(&st);
    printf(" The element at 2 is %d \n", peek(&st,2));
    printf(" The element at 1 is %d \n", peek(&st,1));
    printf("The top element is %d \n", peektop(&st));
    printf("poped %d \n", pop(&st));
    printf("poped %d \n", pop(&st));
    printf("poped %d \n", pop(&st));
    printf("poped %d \n", pop(&st));
    display(&st);
}
