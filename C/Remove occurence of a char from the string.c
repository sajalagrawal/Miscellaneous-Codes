//Author- Sajal Agrawal
//@sajal.agrawal1997@gmail.com

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100],rem;
	int i,j,cont=0;
	printf("Enter string:");
	gets(str);
	printf("Enter char to remove:");
	scanf(" %c",&rem);
    while(1){
        for(i=0;str[i]!='\0';i++){
        cont=0;
        if(str[i]==rem){
            j=i+1;
            //shifting all the elements one place to the left
            while(str[j]!='\0'){
                str[j-1]=str[j];
                j++;
            }
            str[j-1]='\0';
            cont=1;
        }
        if(cont==1)i=-1;
    }
    if(str[i]=='\0')    //no more characters to remove
            break;
    }
	printf("New string: %s",str);
	return 0;
}
