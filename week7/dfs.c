#include <stdio.h>
#include <stdlib.h>

#define MAXV 50

void dfs_rec(int adj[][MAXV], int n, int u, int visited[]){
    visited[u]=1; printf("%d ", u);
    for(int v=0; v<n; v++) if(adj[u][v] && !visited[v]) dfs_rec(adj,n,v,visited);
}

int main(){
    int n; printf("Number of vertices: "); if(scanf("%d", &n)!=1) return 0;
    int adj[MAXV][MAXV]={0};
    printf("Enter adjacency matrix (rows of %d integers):\n", n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &adj[i][j]);
    int start; printf("Start vertex (0-based): "); scanf("%d", &start);
    int visited[MAXV]={0}; printf("DFS: "); dfs_rec(adj,n,start,visited); printf("\n");
    return 0;
}
