#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char pid[30];
	char path1[50] = "/proc/";
	char path2[50];
	int i,j;
	long int cputime=0;
	char string[50];
	char string2[50];
	struct timeval tl,tt;

	printf("give me the pid :");
	scanf("%s",pid);

	strcat(path1,pid);
	strcpy(path2,path1);
	strcat(path1,"/status");
	strcat(path2,"/stat");

	FILE * fp;
	FILE * fp2;

	for(j=1;;j++){

	fp = fopen(path1,"r");
	fp2 = fopen(path2,"r");

        for(i=0;i<15;i++){
                fscanf(fp2, "%s",string);
		if(i==13||i==14){
			cputime += atoi(string);
		}
        }
	memset(string,0,50);	//cpu

	while(1){
		fscanf(fp, "%s",string);
		if(!strcmp(string,"VmSize:"))
			break;
	}
	fscanf(fp,"%s",string);



	printf("total CPU Time : %ld ms\n",100*cputime);
 	printf("Current virtual memory usage: %s kb %d attempt\n",string,j);	//memory



		fclose(fp);
		fclose(fp2);
	sleep(3);
}
	return 0;
}
