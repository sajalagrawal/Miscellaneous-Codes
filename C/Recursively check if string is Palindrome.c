//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
bool isPalindrome(char str[],int start,int end){
    if(str[start]==str[end] && start<end){
        return isPalindrome(str,start+1,end-1);
    }else if(str[start]!=str[end])
        return false;
    return true;
}
int main()
{
    char str[1000];
    //scanf(" %s",str);
    gets(str);
    //printf("str=%s\n",str);
    int n=strlen(str);
    //printf("Len=%d",n);
    if(isPalindrome(str,0,n-1))printf("YES\n");
    else printf("NO\n");
    return 0;
}
