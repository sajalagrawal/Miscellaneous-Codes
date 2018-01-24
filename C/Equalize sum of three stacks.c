//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
int popReq(int stack1[],int n1,int stack2[],int n2,int stack3[],int n3){
    int t1=0,t2=0,t3=0,sum1=0,sum2=0,sum3=0,i,count=0;
    for(i=0;i<n1;i++)sum1+=stack1[i];
    for(i=0;i<n2;i++)sum2+=stack2[i];
    for(i=0;i<n3;i++)sum3+=stack3[i];
    // printf("%d %d %d\n",sum1,sum2,sum3);
    while(1){
        //printf("%d %d %d\n",sum1,sum2,sum3);
        if(sum1==sum2 && sum2==sum3)return count;
        if(sum1>=sum2 && sum1>=sum3 && t1!=n1){
            sum1-=stack1[t1++];
            count++;
        }else if(sum2>=sum3 && sum2>=sum1 && t2!=n2){
            sum2-=stack2[t2++];
            count++;
        }else if(sum3>=sum1 && sum3>=sum2 && t3!=n3){
            sum3-=stack3[t3++];
            count++;
        }
    }
}
int main()
{
    int n1,n2,n3,i;
    printf("Enter size of stack 1:");
    scanf("%d",&n1);
    int stack1[n1];
    printf("Enter elements of stack 1:");
    for(i=0;i<n1;i++)scanf("%d",&stack1[i]);
    printf("Enter size of stack 2:");
    scanf("%d",&n2);
    int stack2[n2];
    printf("Enter elements of stack 2:");
    for(i=0;i<n2;i++)scanf("%d",&stack2[i]);
    printf("Enter size of stack 3:");
    scanf("%d",&n3);
    int stack3[n3];
    printf("Enter elements of stack 3:");
    for(i=0;i<n3;i++)scanf("%d",&stack3[i]);
    printf("No of pops: %d\n",popReq(stack1,n1,stack2,n2,stack3,n3));
    return 0;
}
