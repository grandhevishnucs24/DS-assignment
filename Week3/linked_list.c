#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* create_node(int x){ Node *n=malloc(sizeof(Node)); n->data=x; n->next=NULL; return n; }

void insert_at_position(Node **head, int pos, int val){
    if(pos<0){ printf("Invalid position\n"); return; }
    Node *newn=create_node(val);
    if(pos==0){ newn->next=*head; *head=newn; return; }
    Node *cur=*head; int i=0;
    while(cur && i<pos-1){ cur=cur->next; i++; }
    if(!cur){ printf("Position out of range\n"); free(newn); return; }
    newn->next=cur->next; cur->next=newn;
}

void delete_at_position(Node **head, int pos){
    if(!*head){ printf("List empty\n"); return; }
    if(pos==0){ Node *t=*head; *head=t->next; free(t); return; }
    Node *cur=*head; int i=0;
    while(cur->next && i<pos-1){ cur=cur->next; i++; }
    if(!cur->next){ printf("Position out of range\n"); return; }
    Node *t=cur->next; cur->next=t->next; free(t);
}

int search(Node *head, int val){
    int pos=0; for(Node *cur=head; cur; cur=cur->next, pos++) if(cur->data==val) return pos;
    return -1;
}

void display(Node *head){
    printf("List: ");
    for(Node *cur=head; cur; cur=cur->next) printf("%d ", cur->data);
    printf("\n");
}

int main(){
    Node *head=NULL;
    int ch, pos, val;
    while(1){
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\nChoice: ");
        if(scanf("%d", &ch)!=1) break;
        if(ch==1){ printf("Position: "); scanf("%d", &pos); printf("Value: "); scanf("%d", &val); insert_at_position(&head,pos,val); }
        else if(ch==2){ printf("Position: "); scanf("%d", &pos); delete_at_position(&head,pos); }
        else if(ch==3){ printf("Value to search: "); scanf("%d", &val); int p=search(head,val); if(p==-1) printf("Not found\n"); else printf("Found at position %d\n", p); }
        else if(ch==4) display(head);
        else break;
    }
    return 0;
}
