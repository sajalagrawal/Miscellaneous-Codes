//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com


#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
bool isPalindrome(char str[],int start,int end){
    while(start<=end){
        if(str[start]!=str[end])return false;
        start++;
        end--;
    }
    return true;
}
int solve(char str[],int n){
    int start=0,end=n-1;
    while(start<=end){
        if(str[start]==str[end]){
            start++;end--;
        }else{
            if(isPalindrome(str,start+1,end))
                return start;
            if(isPalindrome(str,start,end-1))
                return end;
            return -1;
        }
    }
    return -2;
}
int main()
{
    printf("Enter str:");
    char str[100];
    scanf("%s",str);
    int n=strlen(str);
    int index=solve(str,n);
    if(index==-1){
        printf("Not possible to remove any char\n");
    }else if(index==-2){
        printf("Complete string is palindrome\n");
    }else{
        printf("Remove char at index:%d\n",index);
    }
    return 0;
}
