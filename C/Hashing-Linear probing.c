/*
 * HASHING- Implementing Linear Probing.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
enum type_of_record {EMPTY,DELETED,OCCUPIED};
struct employee{
    int empid;
    char name[20];
    int age;
};
struct Record{
    struct employee info;
    enum type_of_record status;
};

void del(int key,struct Record table[]);
int search(int key,struct Record table[]);
int hash(int key);
void display(struct Record table[]);
void insert(struct employee emprec,struct Record table[]);
int main()
{
    int i,key,choice;
    struct Record table[MAX];
    struct employee emprec;
    for(i=0;i<MAX;i++)
        table[i].status=EMPTY;
    while(1){
        printf("\n1.Insert a record.\n");
        printf("2.Search a record.\n");
        printf("3.Delete a record.\n");
        printf("4.Display a record.\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter empid, name, age:");
                    scanf("%d%s%d",&emprec.empid,emprec.name,&emprec.age);
                    insert(emprec,table);
                    break;
            case 2: printf("Enter a key to be searched for:");
                    scanf("%d",&key);
                    i=search(key,table);
                    if(i==-1)
                        printf("Key not found.\n");
                    else
                        printf("Key found at index: %d\n",i);
                    break;
            case 3: printf("Enter a key to be deleted:\n");
                    scanf("%d",&key);
                    del(key,table);
                    break;
            case 4: display(table);
                    break;
            case 5: exit(1);
        }
    }
    return 0;
}

void insert(struct employee emprec,struct Record table[]){
    int i,location,h;
    int key=emprec.empid;
    h=hash(key);
    location=h;
    for(i=1;i<=MAX;i++){
        if(table[location].status==EMPTY || table[location].status==DELETED){
            table[location].info=emprec;
            table[location].status=OCCUPIED;
            printf("Record inserted\n");
            return;
        }
        if(table[location].info.empid==key){
            printf("Duplicate key!\n");
            return;
        }
        location=(h+i)%MAX;
    }
    printf("Record couldn't be inserted. Table overflow.\n\n");
}

void display(struct Record table[]){
    int i;
    for(i=0;i<MAX;i++){
        printf("[%d] :",i);
        if(table[i].status==OCCUPIED){
            printf("Occupied:%d %s",table[i].info.empid,table[i].info.name);
            printf("    %d\n",table[i].info.age);
        }
        else if(table[i].status==DELETED)
            printf("Deleted\n");
        else
            printf("Empty\n");
    }
}

int hash(int key){
    return (key%MAX);
}

int search(int key,struct Record table[]){
    int i,h,location;
    h=hash(key);
    location=h;
    for(i=1;i<=MAX;i++){
        if(table[location].status==EMPTY)
            return -1;
        if(table[location].info.empid==key && table[location].status==OCCUPIED)
            return location;
        location=(h+i)%MAX;
    }
    return -1;
}

void del(int key,struct Record table[]){
    int location=search(key,table);
    if(location==-1)
        printf("Key not found.\n");
    else{
         table[location].status=DELETED;
         printf("Record deleted.\n");
    }
}
