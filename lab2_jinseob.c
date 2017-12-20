#include<stdio.h>
int main(){
	FILE *lab2;
	lab2 = fopen("lab2.txt","w");
	fprintf(lab2, "hello world\n");
	fclose(lab2);
	
	return 0;
}
