//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include<stdio.h>
#include <stdlib.h> 
int main(){
int n,m,i; 
printf("Enter n and m:"); 
scanf("%d %d",&n,&m); 
printf("Enter n numbers:"); 
int a[n]; 
for(i=0;i<n;i++)scanf("%d",&a[i]);
double p=(double)m/n;
int count=0;
for(i=1;i<=n;i++){
    if(count<m){
        double r=((rand()%10)/10.0);
        //printf("r=%lf\n",r);
        if(p>=r){
            printf("%d ",a[i]);
            count++;
        }
		p=(double)(m-count)/(n-i);
        
    }else{
        break;
    }    
}
return 0;
}
