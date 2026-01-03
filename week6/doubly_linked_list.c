#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *prev,*next; } Node;
Node* create(int x){ Node *n=malloc(sizeof(Node)); n->data=x; n->prev=n->next=NULL; return n; }

void insert_end(Node **head, int x){ Node *n=create(x); if(!*head){ *head=n; return;} Node *t=*head; while(t->next) t=t->next; t->next=n; n->prev=t; }

void display_forward(Node *h){ printf("Forward: "); while(h){ printf("%d ", h->data); h=h->next; } printf("\n"); }
void display_backward(Node *h){ if(!h){ printf("Backward: \n"); return; } while(h->next) h=h->next; printf("Backward: "); while(h){ printf("%d ", h->data); h=h->prev; } printf("\n"); }

int main(){
    Node *head=NULL; int ch, v;
    while(1){
        printf("\n1.Insert end 2.Display forward 3.Display backward 4.Exit\nChoice: ");
        if(scanf("%d", &ch)!=1) break;
        if(ch==1){ printf("Value: "); scanf("%d", &v); insert_end(&head,v); }
        else if(ch==2) display_forward(head);
        else if(ch==3) display_backward(head);
        else break;
    }
    return 0;
}
