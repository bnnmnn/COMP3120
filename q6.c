#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
int main(){
	int pid1=1, pid2=2;
	const char *msg[]={"apple","banana","chicken"};
	char buffer[BUFFER_SIZE];
	int filedes[2],nRead,i;
	pipe(filedes);
	pid1=fork();
	if(pid1==0){
		close(filedes[0]);
		for(i=0;i<3;i++){
			strcpy(buffer,msg[i]);
			write(filedes[1],buffer,BUFFER_SIZE);
		}
	}
	else{
		pid2=fork();
		if(pid2==0){
			close(filedes[1]);
			printf("child2: ");
			for(i=0;i<3;i++){
				nRead = read(filedes[0],buffer,BUFFER_SIZE);
				printf("%s ",buffer);
			}
			printf("\n");
		}
	}
	return 0;
}
