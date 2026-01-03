#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *left,*right; } Node;
Node* create(int x){ Node *n=malloc(sizeof(Node)); n->data=x; n->left=n->right=NULL; return n; }

Node* insert(Node *root, int x){ if(!root) return create(x); if(x<root->data) root->left=insert(root->left,x); else if(x>root->data) root->right=insert(root->right,x); return root; }

Node* find_min(Node *root){ while(root && root->left) root=root->left; return root; }

Node* delete(Node *root, int x){ if(!root) return NULL; if(x<root->data) root->left=delete(root->left,x); else if(x>root->data) root->right=delete(root->right,x); else{ if(!root->left){ Node *r=root->right; free(root); return r; } else if(!root->right){ Node *l=root->left; free(root); return l; } Node *minr=find_min(root->right); root->data=minr->data; root->right=delete(root->right,minr->data); } return root; }

void inorder(Node *r){ if(!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right); }
void preorder(Node *r){ if(!r) return; printf("%d ", r->data); preorder(r->left); preorder(r->right); }
void postorder(Node *r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->data); }

int main(){
    Node *root=NULL; int ch, v;
    while(1){
        printf("\n1.Insert 2.Delete 3.Inorder 4.Preorder 5.Postorder 6.Exit\nChoice: ");
        if(scanf("%d", &ch)!=1) break;
        if(ch==1){ printf("Value: "); scanf("%d", &v); root=insert(root,v); }
        else if(ch==2){ printf("Value: "); scanf("%d", &v); root=delete(root,v); }
        else if(ch==3){ inorder(root); printf("\n"); }
        else if(ch==4){ preorder(root); printf("\n"); }
        else if(ch==5){ postorder(root); printf("\n"); }
        else break;
    }
    return 0;
}
