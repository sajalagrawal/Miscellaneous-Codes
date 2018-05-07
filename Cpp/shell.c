/*
Sajal Agrawal [0801CS151065]
*/

//#include <stdlib.h>
#include <string.h>	 //strcmp(), strtok()
#include <unistd.h>	 //execvp(), fork()
#include <sys/types.h>   //wait()
#include <fcntl.h>	 //pipe()
#include <stdio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


int flag=0;
int executeCommand(char **arguments){
    int i=fork();
    if(i==0){
        if(execvp(arguments[0],arguments)<0){
            printf("Error\n");
        }
    }else{
        wait();
    }
}

int main(){
    int i,k=0,in,out;
    char command[100],*arguments[50];
    char *s,*ch;
    printf("Sajal Agrawal\n");
    while(1){
        iterate:
        k=0;
        printf(CYN "\n#MYSHELL >>$" RESET);
        scanf("%[^\n]",command);
	getchar();
        arguments[k]=strtok(command," ");
	while(arguments[k]!=NULL){
		  arguments[++k]=strtok(NULL," ");
		  if(strcmp(arguments[k-1],"|")==0){
		  		flag=1;
		  }else if (strcmp(arguments[k-1],"&")==0){
		  		flag=2;
		  }else if(strcmp(arguments[k-1],">")==0){
				flag=3;
	  	  }else if(strcmp(arguments[k-1],"<")==0){
				flag=4;
	  	  }
	}
        int t=0;
        if(flag==1){
		int fds[2];
	  	char *pre[10],*next[10];
		for(i=0;strcmp(arguments[i],"|");i++)
		  	pre[i]=arguments[i];
		pre[i]=NULL;
		t=0;
		i++;
		for(;i<k;i++)
		  	next[t++]=arguments[i];
		next[t]=NULL;
		int i=fork();
		if(i==0){
			pipe(fds);
			int j=fork();
			if(j==0){
			  	close(1);
			  	dup(fds[1]);
				if(execvp(pre[0],pre)<0)
		  		    	printf("Error\n");
		      }else{
		      	close(0);
		      	dup(fds[0]);
		      	close(fds[0]);
		      	close(fds[1]);
		      	execvp(next[0],next);
		      }
		}else{
		  	wait();
		}
	}
	else if(flag==2){
  		arguments[k-1]=NULL;
		int i=fork();
	    	if(i==0){
	  	        if(execvp(arguments[0],arguments)<0){
		        	printf("Error\n");
		    }else{
		        //wait();
		        goto iterate;
		    }
		}
	}
	else if(flag==3){
		int out;
	   	char *pre[10];
		for(i=0;strcmp(arguments[i],">");i++){
		  	pre[i]=arguments[i];
		}
		pre[i]=NULL;
		out=open(arguments[i+1],O_RDWR|O_CREAT|O_APPEND,777);
		int std_out=dup(fileno(stdout));
		dup2(out,fileno(stdout));
		int j=0;
		int id=fork();
		if(id==0){
			execvp(pre[0],pre);
		}else{
			wait();
		}
		fflush(stdout);
		close(out);
		dup2(std_out,fileno(stdout));
		close(std_out);
	}
	else if(flag==4){
		char *pre[10];
		for(i=0;strcmp(arguments[i],"<");i++){
			pre[i]=arguments[i];
		}
			pre[i]=NULL;


		int in = open(arguments[i+1],O_RDWR|O_CREAT|O_APPEND,777);
		int std_in=dup(fileno(stdin));
		dup2(in,fileno(stdin));
		int j=0;
		int id = fork();
		if(id==0) {
			execvp(pre[0],pre);
		} else {
			wait();
		}

		fflush(stdout);
		close(in);
		dup2(std_in,fileno(stdin));
		close(std_in);
	}
	else{
		executeCommand(arguments);
	}
   }
  return 0;
}
