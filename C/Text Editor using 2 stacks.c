/*
 * Text Editor Implementation using 2 stacks
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */
 
#include <stdio.h>
#include <stdlib.h>
struct stack{
    char ch;
    struct stack *next;
};
typedef struct stack STACK;
STACK *LeftS_Top=NULL;      //left stack's top
STACK *RightS_Top=NULL;     //right stack's top

//member functions
int numNodesStack(STACK*);
void displayStacks();
void addToLeftStack(char[]);
void pushToLeftStack(char);
char popFromLeftStack();
void pushToRightStack(char);
char popFromRightStack();
void moveCursor(int);

int main()
{
    int choice,pos;
    char ans='y',str[80],moved,garbage;
    while(ans=='y' || ans=='Y'){
        printf("MENU-");
        printf("\n1.Add data.");
        printf("\n2.Move Cursor to a specified position.");
        printf("\n3.Move cursor left.");
        printf("\n4.Move cursor right.");
        printf("\n5.Delete character using DEL.");
        printf("\n6.Delete character using Backspace.");
        printf("\n7.Exit.");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the word to be inserted:");
                    getchar();
                    gets(str);
                    addToLeftStack(str);
                    break;
            case 2: printf("Enter position from beginning(1-base indexing):");
                    scanf("%d",&pos);
                    moveCursor(pos);
                    break;
            case 3: if(LeftS_Top!=NULL){
                        moved=popFromLeftStack();
                        pushToRightStack(moved);
                        printf("\nCursor moved one position left.\n");
                    }
                    break;
            case 4: if(RightS_Top!=NULL){
                        moved=popFromRightStack();
                        pushToLeftStack(moved);
                        printf("\nCursor moved one position right.\n");
                    }
                    break;
            case 5: garbage=popFromRightStack();
                    break;
            case 6: garbage=popFromLeftStack();
                    break;
            case 7: printf("Process terminated.\n");
                    exit(0);
                    break;
            default: printf("\nWrong choice! TRY AGAIN.\n");
        }
        displayStacks();
        printf("\n\nDo you want to continue?(Y/N):");
        scanf(" %c",&ans);
    }
    return 0;
}

int numNodesStack(STACK *t){
    STACK *temp=t;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void displayStacks(){
    if(LeftS_Top==NULL){
        printf("\nLeftStack: empty");
    }else{
        printf("\nLeftStack: %c,%d",LeftS_Top->ch,numNodesStack(LeftS_Top));
    }
    if(RightS_Top==NULL){
        printf("\tRightStack: empty");
    }else{
        printf("\tRightStack: %c,%d",RightS_Top->ch,numNodesStack(RightS_Top));
    }
}

void addToLeftStack(char str[]){
    int i=0;
    while(str[i]!='\0'){
        pushToLeftStack(str[i]);
        i++;
    }
}

void pushToLeftStack(char c){
    STACK *new=(STACK*)malloc(sizeof(STACK));
    new->ch=c;
    new->next=LeftS_Top;
    LeftS_Top=new;
}

char popFromLeftStack(){
    if(LeftS_Top==NULL){
        return;
    }
    char temp=LeftS_Top->ch;
    LeftS_Top=LeftS_Top->next;
    return (temp);
}

void pushToRightStack(char c){
    STACK *new=(STACK*)malloc(sizeof(STACK));
    new->ch=c;
    new->next=RightS_Top;
    RightS_Top=new;
}

char popFromRightStack(){
    if(RightS_Top==NULL){
        return;
    }
    char temp=RightS_Top->ch;
    RightS_Top=RightS_Top->next;
    return (temp);
}

void moveCursor(int pos){
    int count,i;
    char moved;
    if(pos<numNodesStack(LeftS_Top)){    //moving to a position before cursor
        count=numNodesStack(LeftS_Top)-pos;
        for(i=0;i<count;i++){
            moved=popFromLeftStack();
            pushToRightStack(moved);
        }
    }else if(pos>numNodesStack(LeftS_Top)){     //moving to a position after cursor
        count=pos-numNodesStack(LeftS_Top);
        for(i=0;i<count;i++){
            moved=popFromRightStack();
            pushToLeftStack(moved);
        }
    }
}
