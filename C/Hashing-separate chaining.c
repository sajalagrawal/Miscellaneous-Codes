/*
 * HASHING- Implementing separate chaining collision resolution technique.
 * Author- SAJAL AGRAWAL
 * @sajal.agrawal1997@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

//node for each record
struct record{
    int data;
    struct record* link;
};

void insert(int in,struct record *table[],int size);
int search(int key,struct record *table[],int size);
void display(struct record *table[],int size);
int hash(int key,int size);
void del(int key,struct record *table[],int size);

int main()
{
    //input array from question
    int a[]={384, 887, 778, 916, 794, 336, 387, 493, 650, 422, 363, 28, 691, 60, 764, 927, 541, 427, 173, 737, 212,
    369, 568, 430, 783, 531, 863, 124, 68, 136, 930, 803, 23, 59, 70, 168, 394, 457, 12, 43, 230, 374, 422,
    920, 785, 538, 199, 325, 316, 371, 414, 527, 92, 981, 957, 874, 863, 171, 997, 282, 306, 926, 85, 328,
    337, 506, 847, 730, 314, 858, 125, 896, 583, 546, 815, 368, 435, 365, 44, 751, 88, 809, 277, 179, 789,
    585, 404, 652, 755, 400, 933, 61, 677, 369, 740, 13, 227, 587, 95, 540, 9386, 889, 2780, 6918, 7796,
    8338, 5389, 495, 6652, 1424, 2365, 30, 8693, 62, 7766, 3929, 543, 3429, 9175, 5739, 5214, 5371,
    2570, 6432, 5785, 1533, 2865, 5126, 4070, 3138, 3932, 9805, 4025, 3061, 3072, 8170, 1396, 8459,
    5014, 8045, 6232, 7376, 4424, 4922, 3787, 8540, 5201, 4327, 8318, 4373, 6416, 3529, 6094, 8983,
    9959, 1876, 6865, 9173, 6999, 7284, 2308, 928, 7087, 6330, 339, 6508, 849, 1732, 1316, 5860, 6127,
    3898, 9585, 548, 8817, 3370, 5437, 367, 4046, 3753, 1090, 6811, 7279, 7181, 5791, 3587, 5406, 2654,
    2757, 2402, 9935, 5063, 9679, 3371, 7742, 15, 6229, 8589, 8097, 7542, 86, 89, 80, 18, 96, 38, 89, 95,
    52, 24, 65, 30, 93, 62, 66, 29, 43, 29, 75, 39, 14, 71, 70, 32, 85, 33, 65, 26, 70, 38, 32, 5, 25, 61, 72,
    70, 96, 59, 14, 45, 32, 76, 24, 22, 87, 40, 101, 27, 18, 73, 16, 29, 94, 83, 59, 76, 65, 73, 99, 84, 8, 28,
    87, 30, 39, 8, 49, 32, 16, 60, 27, 98, 85, 48, 17, 70, 37, 67, 46, 53, 90, 11, 79, 81, 91, 87, 6, 54, 57,
    102, 35, 63, 79, 71, 42, 15, 29, 89, 97, 42};

    int n=sizeof(a)/sizeof(a[0]);
    //size of a[] is 300
    //printf("Enter size of hash table:");
    //scanf("%d",&n);
    //load factor=20;
    int size=n/20;
    struct record *table[size];
    int choice,in,i,key;
    //for(i=0;i<300;i++)printf("%d ",a[i]);
    for(i=0;i<size;i++)
        table[i]=NULL;
    while(1){
        printf("\nMENU-\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: //printf("Enter data:");   //for taking i/p at runtime
                    //scanf("%d",&in);
                    //insert(in,table);
                    for(i=0;i<300;i++){
                        insert(a[i],table,size);
                    }
                    break;
           case 2: printf("Enter a key to be searched:");
                   scanf("%d",&key);
                   i=search(key,table,size);
                   if(i==-1)
                        printf("key %d not found\n",key);
                   else
                        printf("key found in chain %d\n",i);
                   break;
           case 3: printf("Enter a key to be deleted:");
                   scanf("%d",&key);
                   del(key,table,size);
                   break;
           case 4: display(table,size);
                   break;
           case 5: exit(1);
        }
    }
    return 0;
}

//inserts a particular key if not already present in the hash table
void insert(int in,struct record *table[],int size){
    int h;
    struct record *tmp;
    if(search(in,table,size)!=-1){
        //printf("Duplicate key!\n");
        return;
    }
    h=hash(in,size);
    //insert in the beginning of the list
    tmp=malloc(sizeof(struct record));
    tmp->data=in;
    tmp->link=table[h];
    table[h]=tmp;
}

//searches a particular key in the hash table
int search(int key,struct record *table[],int size){
    int h;
    h=hash(key,size);
    struct record *ptr;
    ptr=table[h];
    while(ptr!=NULL){
        if(ptr->data==key)
            return h;
        ptr=ptr->link;
    }
    return -1;
}

//calculates hash value for each key
int hash(int key,int size){
    return (key%size);
}

//Displays hash table
void display(struct record *table[],int size){
    int i;
    struct record *ptr;
    for(i=0;i<size;i++){
        printf("\n[%d] ",i);
        if(table[i]!=NULL){
            ptr=table[i];
            while(ptr!=NULL){
                printf("%d ",ptr->data);
                ptr=ptr->link;
            }
        }
    }
    printf("\n");
}

//Deleting a particular element from hash table
void del(int key,struct record *table[],int size){
    int h;
    struct record *tmp,*ptr;
    h=hash(key,size);
    if(table[h]==NULL){
        printf("Key %d not found.\n",key);
        return;
    }
    if(table[h]->data==key){
        tmp=table[h];
        table[h]=table[h]->link;
        free(tmp);
        return;
    }
    ptr=table[h];
    while(ptr->link!=NULL){
        if(ptr->link->data==key){
            tmp=ptr->link;
            ptr->link=tmp->link;
            free(tmp);
            return;
        }
        ptr=ptr->link;
    }
    printf("key %d not found.\n",key);
}
