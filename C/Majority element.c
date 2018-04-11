//Author - Sajal Agrawal 
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
void solve(int a[],int n){
    int majorityEle=0,count=1,i;
    for(i=1;i<n;i++){
        if(a[i]==a[majorityEle])count++;
        else count--;
        if(count==0){
            majorityEle=i+1;
            i++;
            count=1;
        }
        if(majorityEle>=n)break;
    }
    count=0;
    int majorityValue=a[majorityEle];
    for(i=0;i<n;i++){
        if(a[i]==majorityValue)count++;
    }
    if(count>n/2)printf("Majority ele:%d",majorityValue);
    else printf("No majority element.");
}
int main()
{
    int n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    solve(a,n);
    return 0;
}
