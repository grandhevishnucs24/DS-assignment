#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *next; } Node;
Node* create_node(int x){ Node *n=malloc(sizeof(Node)); n->data=x; n->next=NULL; return n; }

void append(Node **h, int x){ Node *n=create_node(x); if(!*h){ *h=n; return;} Node *t=*h; while(t->next) t=t->next; t->next=n; }

void delete_value(Node **h, int x){
    while(*h && (*h)->data==x){ Node *t=*h; *h=(*h)->next; free(t); }
    Node *cur=*h;
    while(cur && cur->next){ if(cur->next->data==x){ Node *t=cur->next; cur->next=t->next; free(t);} else cur=cur->next; }
}

void bubble_sort(Node *h){
    if(!h) return;
    int swapped;
    do{
        swapped=0; Node *p=h;
        while(p->next){ if(p->data>p->next->data){ int t=p->data; p->data=p->next->data; p->next->data=t; swapped=1; } p=p->next; }
    } while(swapped);
}

Node* reverse(Node *h){ Node *prev=NULL, *cur=h; while(cur){ Node *nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; } return prev; }

void concat(Node **a, Node **b){ if(!*a){ *a=*b; return;} Node *t=*a; while(t->next) t=t->next; t->next=*b; }

void display(Node *h){ printf("List: "); for(Node *p=h;p;p=p->next) printf("%d ", p->data); printf("\n"); }

int main(){
    Node *list1=NULL, *list2=NULL;
    int ch, v;
    while(1){
        printf("\n1.Append to L1 2.Append to L2 3.Delete value from L1 4.Sort L1 5.Reverse L1 6.Concat L1,L2 7.Display 8.Exit\nChoice: ");
        if(scanf("%d", &ch)!=1) break;
        if(ch==1){ printf("Value: "); scanf("%d", &v); append(&list1,v); }
        else if(ch==2){ printf("Value: "); scanf("%d", &v); append(&list2,v); }
        else if(ch==3){ printf("Value to delete from L1: "); scanf("%d", &v); delete_value(&list1,v); }
        else if(ch==4) bubble_sort(list1);
        else if(ch==5) list1=reverse(list1);
        else if(ch==6){ concat(&list1,&list2); }
        else if(ch==7){ printf("L1: "); display(list1); printf("L2: "); display(list2); }
        else break;
    }
    return 0;
}
