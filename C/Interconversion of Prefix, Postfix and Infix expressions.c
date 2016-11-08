/*
 * Interconversion of Prefix, Postfix and Infix expressions using stacks.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 -------------------------------------
 * Example for interconversion-
 * Infix: (a-b/c)*(d*e-f)
 * Postfix: abc/-de*f-*
 * Prefix: *-a/bc-*def
*/

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h> //for isalnum()
#include<string.h> //for strlen(), strrev()

struct node{
    char data;
    char str[80];
    struct node *next;
};
typedef struct node NODE;
NODE *top=NULL;

//member functions
char pop();   //pops the char data part of node from stack
void push(char);    //pushes the char data part of node into stack
int priority(char);   //determines priority of operators
void infixToPostfix(char[],char[]);   //converts infix To Postfix
void infixToPrefix(char[],char[]);    //converts infix To Prefix
void postfixToInfix(char[],char[]);   //converts postfix To Infix
void prefixToInfix(char[],char[]);    //converts prefix To Infix
void pushString(char *substr);  //pushes the char str[] part of node into stack
void popString(char *res);  //pops the char str[] part of node from stack
void postfixToPrefix(char[],char[]);  //converts postfix To Prefix
void prefixToPostfix(char[],char[]);  //converts prefix To Postfix

int main()
{
    int choice;
    char exp[80],res[80];
    printf("Menu-");
    printf("\n1.Infix to Postfix.");
    printf("\n2.Infix to Prefix.");
    printf("\n3.Postfix to Infix.");
    printf("\n4.Postfix to Prefix.");
    printf("\n5.Prefix to Infix.");
    printf("\n6.Prefix to Postfix.");
    printf("\n7.Exit.");
    printf("\nEnter choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter the Infix exp:");
                scanf("%s",exp);
                infixToPostfix(exp,res);
                printf("Postfix: %s\n",res);
                break;
        case 2: printf("Enter the Infix exp:");
                scanf("%s",exp);
                infixToPrefix(exp,res);
                printf("Prefix: %s\n",res);
                break;
        case 3: printf("Enter the Postfix exp:");
                scanf("%s",exp);
                postfixToInfix(exp,res);
                printf("Infix: %s",res);
                break;
        case 4: printf("Enter the Postfix exp:");
                scanf("%s",exp);
                postfixToPrefix(exp,res);
                printf("Prefix: %s",res);
                break;
        case 5: printf("Enter the Prefix exp:");
                scanf("%s",exp);
                prefixToInfix(exp,res);
                printf("Infix: %s",res);
                break;
        case 6: printf("Enter the Prefix exp:");
                scanf("%s",exp);
                prefixToPostfix(exp,res);
                printf("Postfix: %s",res);
                break;
        case 7: printf("Process terminated.\n");
                exit(0);
        default: printf("Wrong input. TRY AGAIN.");
    }
    return 0;
}

void push(char x){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;
    temp->next=top;
    top=temp;
}

char pop(){
    if (top == NULL){
        printf("UNDERFLOW");
        exit(0);
    }else{
        char temp=top->data;
        top = top->next;
        return(temp);
    }
}


int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return -1;
}

void infixToPostfix(char infix[],char postfix[]){
    int i=0,j=0,k;
    char x;
    for(k=strlen(infix);k>=1;k--){
        infix[k]=infix[k-1];
    }
    infix[0]='(';
    infix[strlen(infix)+1]=')';
    while(infix[i] != '\0'){
        if(isalnum(infix[i])){
            postfix[j]=infix[i];
            j++;
        }else if(infix[i] == '('){
            push(infix[i]);
        }else if(infix[i] == ')'){
            while((x = pop()) != '('){
                postfix[j]=x;
                j++;
            }
        }else{
            while(priority(top->data) >= priority(infix[i])){
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
        }
        i++;
    }
    while(top != NULL){
        postfix[j]=pop();
        j++;
    }
    postfix[j-1]='\0';
}

void infixToPrefix(char infix[],char prefix[]){
    int i=0;
    infix=strrev(infix);
    for(;i<strlen(infix);i++){
        if(infix[i]=='('){
            infix[i]=')';
        }else if(infix[i]==')'){
            infix[i]='(';
        }
    }
    infixToPostfix(infix,prefix);
    prefix=strrev(prefix);
}

void popString(char *res) {
    if(top == NULL) {
            printf("Stack Underflow\n");
            exit(0);
    }else{
            strcpy(res, top->str);   //des,source
            top = top->next;
    }
    return;
}

void pushString(char *substr){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    strcpy(temp->str, substr);
    temp->next=top;
    top=temp;
}

void postfixToInfix(char postfix[],char infix[]){
    int i=0,len;
    char buffer1[100],buffer2[200],t[2];
    for(;i<strlen(postfix);i++){
        if(isalnum(postfix[i])){
            t[0]=postfix[i];
            t[1]='\0';
            pushString(t);
        }else{
            popString(buffer1);
            popString(buffer2);
            len = strlen(buffer2);
            buffer2[len++] = postfix[i];
            buffer2[len] = '\0';
            strcat(buffer2, buffer1);
            pushString(buffer2);
        }
    }
    strcpy(infix,top->str);
}

void prefixToInfix(char prefix[],char infix[]){
    int i=0,len;
    char buffer1[100],buffer2[200],t[2];
    prefix=strrev(prefix);
    for(;i<strlen(prefix);i++){
        if(isalnum(prefix[i])){
            t[0]=prefix[i];
            t[1]='\0';
            pushString(t);
        }else{
            popString(buffer2);
            popString(buffer1);
            len = strlen(buffer2);
            buffer2[len++] = prefix[i];
            buffer2[len] = '\0';
            strcat(buffer2, buffer1);
            pushString(buffer2);
        }
    }
    strcpy(infix,top->str);
}

void postfixToPrefix(char postfix[],char prefix[]){
    int i=0;
    char buffer1[100],buffer2[200],t[2],str[100];
    for(;i<strlen(postfix);i++){
        if(isalnum(postfix[i])){
            t[0]=postfix[i];
            t[1]='\0';
            pushString(t);
        }else{
            popString(buffer1);
            popString(buffer2);
            t[0]=postfix[i];
            t[1]='\0';
            strcpy(str, t);
            strcat(str, buffer2);
            strcat(str, buffer1);
            pushString(str);
        }
    }
    strcpy(prefix,top->str);
}

void prefixToPostfix(char prefix[],char postfix[]){
    int i=0;
    char buffer1[100],buffer2[100],t[2],res[200];
    prefix=strrev(prefix);
    for(;i<strlen(prefix);i++){
        if(isalnum(prefix[i])){
            t[0]=prefix[i];
            t[1]='\0';
            pushString(t);
        }else{
            popString(buffer1);
            popString(buffer2);
            strcpy(res, buffer1);
            strcat(res, buffer2);
            t[0]=prefix[i];
            t[1]='\0';
            strcat(res, t);
            pushString(res);
        }
    }
    strcpy(postfix,top->str);
}
