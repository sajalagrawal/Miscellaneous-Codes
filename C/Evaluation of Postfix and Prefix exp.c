/*
 * Evaluation of Postfix and Prefix expressions using stacks
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */
 
#include <stdio.h>
#include <stdlib.h>
#include<string.h> //for strlen()
#include<ctype.h> //for isaplha()

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *top=NULL;

//member functions
int pop();
void push(int);
void evaluate(char,int,int);

int main()
{
    char str[50];
    int a,b,i,val,choice;
    printf("Menu-");
    printf("\n1.Evaluation of Postfix.");
    printf("\n2.Evaluation of Prefix.");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter the Postfix expression:");
                getchar();
                gets(str);
                for (i=0;i<strlen(str);i++){
                    //if the user enters numbers instead of variables in the expression. Won't work for 2-digit numbers
                    if (str[i] >= 48 && str[i] <= 57){
                        push(str[i]-'0');
                    }else if(isalpha(str[i])){      //if the user enters variables in the expression.
                        printf("Enter the value of %c:",str[i]);
                        scanf("%d",&val);
                        push(val);
                    }else if (str[i]>= 42 && str[i]<= 47){    //operators in the expression.
                        a=pop();
                        b=pop();
                        evaluate(str[i],b,a);
                    }
                }
                printf("Ans is: %d",pop());
                break;
        case 2: printf("Enter the Prefix expression:");
                getchar();
                gets(str);
                for (i=strlen(str)-1;i>=0;i--){
                    //if the user enters numbers instead of variables in the expression. Won't work for 2-digit numbers
                    if (str[i] >= 48 && str[i] <= 57){
                        push(str[i]-'0');
                    }else if(isalpha(str[i])){      //if the user enters variables in the expression.
                        printf("Enter the value of %c:",str[i]);
                        scanf("%d",&val);
                        push(val);
                    }else if (str[i]>= 42 && str[i]<= 47){    //operators in the expression.
                        a=pop();
                        b=pop();
                        evaluate(str[i],a,b);
                    }
                }
                printf("Ans is: %d",pop());
                break;
            default: printf("Wrong choice. TRY AGAIN.");
    }
    return 0;
}

void push(int x){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;
    temp->next=top;
    top=temp;
}

int pop(){
    if (top == NULL){
        printf("UNDERFLOW");
        exit(0);
    }
    else{
        int temp=top->data;
        top = top->next;
        return(temp);
    }
}

void evaluate(char ch,int a,int b){         //ch holds operator (+,-,*,/)
    switch(ch){
        case '+':
            push(a+b);
            break;
        case '-':
            push(a-b);
            break;
        case '*':
            push(a*b);
            break;
        case '/':
            push(a/b);
            break;
    }
}
