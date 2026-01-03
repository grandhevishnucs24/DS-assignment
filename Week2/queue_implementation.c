#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int front, rear;
} Queue;

void init(Queue *q){ q->front=0; q->rear=0; }
int is_empty(Queue *q){ return q->front==q->rear; }
int is_full(Queue *q){ return q->rear==MAX; }

void enqueue(Queue *q, int x){
    if(is_full(q)){ printf("Queue overflow\n"); return; }
    q->data[q->rear++]=x;
}

int dequeue(Queue *q){
    if(is_empty(q)){ printf("Queue underflow\n"); return -1; }
    return q->data[q->front++];
}

void display(Queue *q){
    if(is_empty(q)){ printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for(int i=q->front;i<q->rear;i++) printf("%d ", q->data[i]);
    printf("\n");
}

int main(){
    Queue q; init(&q);
    int choice, val;
    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        if(scanf("%d", &choice)!=1) break;
        if(choice==1){ printf("Value: "); scanf("%d", &val); enqueue(&q,val); }
        else if(choice==2){ val=dequeue(&q); if(val!=-1) printf("Dequeued: %d\n", val); }
        else if(choice==3) display(&q);
        else break;
    }
    return 0;
}
