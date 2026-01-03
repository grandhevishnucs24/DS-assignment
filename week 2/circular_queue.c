#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct{
    int data[SIZE];
    int front, rear; // front points to element, rear points to next insertion index
} CQueue;

void init(CQueue *q){ q->front=0; q->rear=0; }
int is_empty(CQueue *q){ return q->front==q->rear; }
int is_full(CQueue *q){ return ((q->rear+1)%SIZE)==q->front; }

void enqueue(CQueue *q, int x){
    if(is_full(q)){ printf("Circular Queue overflow\n"); return; }
    q->data[q->rear]=x;
    q->rear = (q->rear+1)%SIZE;
}

int dequeue(CQueue *q){
    if(is_empty(q)){ printf("Circular Queue underflow\n"); return -1; }
    int v = q->data[q->front];
    q->front = (q->front+1)%SIZE;
    return v;
}

void display(CQueue *q){
    if(is_empty(q)){ printf("Empty\n"); return; }
    printf("Circular Queue: ");
    for(int i=q->front; i!=q->rear; i=(i+1)%SIZE) printf("%d ", q->data[i]);
    printf("\n");
}

int main(){
    CQueue q; init(&q);
    int ch, x;
    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        if(scanf("%d", &ch)!=1) break;
        if(ch==1){ printf("Value: "); scanf("%d", &x); enqueue(&q,x); }
        else if(ch==2){ x=dequeue(&q); if(x!=-1) printf("Dequeued: %d\n", x); }
        else if(ch==3) display(&q);
        else break;
    }
    return 0;
}
