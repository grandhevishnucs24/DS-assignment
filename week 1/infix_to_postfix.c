#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int is_operator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

int precedence(char c){
    switch(c){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

int is_right_associative(char c){
    return (c=='^');
}

void infix_to_postfix(const char *infix, char *postfix){
    char stack[MAX];
    int top=-1, k=0;
    for(int i=0; infix[i]; i++){
        char c = infix[i];
        if(isspace(c)) continue;
        if(isalnum(c)){
            postfix[k++]=c;
        } else if(c=='('){
            stack[++top]=c;
        } else if(c==')'){
            while(top!=-1 && stack[top]!='(') postfix[k++]=stack[top--];
            if(top!=-1 && stack[top]=='(') top--; // pop '('
        } else if(is_operator(c)){
            while(top!=-1 && is_operator(stack[top])){
                char topOp = stack[top];
                int pTop = precedence(topOp);
                int pCurr = precedence(c);
                if(pTop>pCurr || (pTop==pCurr && !is_right_associative(c))){
                    postfix[k++]=stack[top--];
                } else break;
            }
            stack[++top]=c;
        } else {
            // unknown char - copy
            postfix[k++]=c;
        }
    }
    while(top!=-1) postfix[k++]=stack[top--];
    postfix[k]='\0';
}

int main(){
    char infix[256];
    char postfix[256];
    printf("Enter infix expression (operators: + - * / ^, parentheses allowed):\n");
    if(!fgets(infix, sizeof(infix), stdin)) return 0;
    // remove trailing newline
    infix[strcspn(infix, "\n")] = '\0';
    infix_to_postfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
