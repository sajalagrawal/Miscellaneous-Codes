//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
double power(double x,int y){
    double res=1;
    while(y--){
        res=res*x;
    }
    return res;
}

double power2(double x,int y){
    //printf("%lf %d\n",x,y);
    if(y==0)return 1;
    double temp=power2(x,y/2);
    if(y&1)return x*temp*temp;
    return temp*temp;
}
int main()
{
    double x;
    int y;
    printf("Enter x and y:");
    scanf("%lf %d",&x,&y);
    printf("ans=%lf\n",power2(x,y));
    return 0;
}
