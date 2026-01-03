#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11

typedef struct Entry{ int key; int value; struct Entry *next; } Entry;
Entry* table[TABLE_SIZE];

int hash(int key){ return (key%TABLE_SIZE+TABLE_SIZE)%TABLE_SIZE; }

void insert(int key,int value){ int idx=hash(key); Entry *e=malloc(sizeof(Entry)); e->key=key; e->value=value; e->next=table[idx]; table[idx]=e; }

Entry* search(int key){ int idx=hash(key); for(Entry *e=table[idx]; e; e=e->next) if(e->key==key) return e; return NULL; }

void delete_key(int key){ int idx=hash(key); Entry *e=table[idx], *prev=NULL; while(e){ if(e->key==key){ if(prev) prev->next=e->next; else table[idx]=e->next; free(e); return; } prev=e; e=e->next; } printf("Key not found\n"); }

void display(){
    for(int i=0;i<TABLE_SIZE;i++){
        printf("%d:", i);
        for(Entry *e=table[i]; e; e=e->next) printf(" -> (%d,%d)", e->key, e->value);
        printf("\n");
    }
}

int main(){
    memset(table,0,sizeof(table));
    int ch,k,v;
    while(1){
        printf("\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\nChoice: "); if(scanf("%d", &ch)!=1) break;
        if(ch==1){ printf("Key: "); scanf("%d", &k); printf("Value: "); scanf("%d", &v); insert(k,v); }
        else if(ch==2){ printf("Key: "); scanf("%d", &k); Entry *e=search(k); if(e) printf("Found: %d\n", e->value); else printf("Not found\n"); }
        else if(ch==3){ printf("Key: "); scanf("%d", &k); delete_key(k); }
        else if(ch==4) display();
        else break;
    }
    return 0;
}
