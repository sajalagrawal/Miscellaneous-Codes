//Author - Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[100],str2[100];
    printf("Enter str1:");
    scanf("%s",str1);
    printf("Enter str2:");
    scanf("%s",str2);
    //printf(" %s %s",str1,str2);
    int hash1[26]={0},hash2[26]={0},i=0;
    while(str1[i]!='\0')hash1[str1[i++]-'a']++;
    i=0;
    while(str2[i]!='\0')hash2[str2[i++]-'a']++;
    for(i=0;i<26;i++){
        //printf("%d %d\n",hash1[i],hash2[i]);
        if(hash1[i]!=hash2[i]){
            printf("NOT possible\n");
            break;
        }
    }
    if(i==26)printf("YES possible\n");
    return 0;
}
