#include <stdio.h>
#include <stdlib.h>

#define MAXV 50

typedef struct{ int items[MAXV]; int front,rear; } Queue;
void qinit(Queue *q){ q->front=0; q->rear=0; }
void qpush(Queue *q,int x){ q->items[q->rear++]=x; }
int qpop(Queue *q){ return q->items[q->front++]; }
int qempty(Queue *q){ return q->front==q->rear; }

void bfs(int adj[][MAXV], int n, int start){
    int visited[MAXV]={0};
    Queue q; qinit(&q);
    visited[start]=1; qpush(&q,start);
    printf("BFS: ");
    while(!qempty(&q)){
        int u=qpop(&q); printf("%d ", u);
        for(int v=0; v<n; v++) if(adj[u][v] && !visited[v]){ visited[v]=1; qpush(&q,v); }
    }
    printf("\n");
}

int main(){
    int n;
    printf("Number of vertices: "); if(scanf("%d", &n)!=1) return 0;
    int adj[MAXV][MAXV]={0};
    printf("Enter adjacency matrix (rows of %d integers):\n", n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &adj[i][j]);
    int start; printf("Start vertex (0-based): "); scanf("%d", &start);
    bfs(adj,n,start);
    return 0;
}
