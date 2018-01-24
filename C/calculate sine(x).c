//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include<stdio.h>
#include<stdbool.h>
#define ll long long
ll sub=0,add=0,mult=0,div=0,fcall=0;
double power(double x,int y){
	//x^y;
	fcall++;
	if(y==0)return 1;
	double temp=power(x,y/2);
	if(y%2==0){
		return temp*temp;
		mult++;
	}
	mult++;
	return temp*temp*x;
}

double fact(int n){
	fcall++;
	if(n<=1)return 1;
	mult++;
	return n*fact(n-1);
}

double sin(double x){
	fcall++;
	int i,exp=1;
	double res=0;
	bool minus=false;
	for(i=0;i<18;i++){
		//printf("cur res=%lf\n",res);
		if(minus){
			res=res-(double)power(x,exp)/fact(exp);
			sub++;
			div++;
		}
		else{
			res=res+(double)power(x,exp)/fact(exp);
			add++;
			div++;
		}
		exp=exp+2;
		minus=!minus;
	}
	return res;
}
int main(){
	double x;
	printf("Enter x:");
	scanf("%lf",&x);
	//printf("junk=%lld",power(2,4));
	//printf("junk=%lld",fact(5));
	x=(22*x)/(7*180);
	//printf("new x=%lf",x);
	double ans=sin(x);
	printf("sine=%lf\n",ans);
	printf("Number of addition:%lld\n",add);
	printf("Number of subtraction:%lld\n",sub);
	printf("Number of Mult:%lld\n",mult);
	printf("Number of div:%lld\n",div);
	printf("Number of function calls:%lld\n",fcall);
	return 0;
}



//Optimized solution
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
double sin(double x){
    double ans=x,term=x;
    bool minus=true;
    int i;
    for(i=1;i<100;i++){
        term=(term*x*x)/((2*i)*(2*i+1));
        if(minus)ans-=term;
        else ans+=term;
        minus=!minus;
    }
    return ans;
}
int main()
{
    double x;
	printf("Enter x:");
	scanf("%lf",&x);
	//printf("junk=%lld",power(2,4));
	//printf("junk=%lld",fact(5));
	x=(22*x)/(7*180);
	//printf("new x=%lf",x);
	double ans=sin(x);
	printf("Answer:%lf\n",ans);
    return 0;
}
