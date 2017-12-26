#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
int main(void){
	struct timeval time;
	struct tm *clock;
	gettimeofday(&time,NULL);
	clock = localtime(&time.tv_sec);
	printf("year:	%d\n",clock->tm_year+1900);
	printf("month:	%d\n",clock->tm_mon+1);
	printf("day:	%d\n",clock->tm_mday);
	printf("hour:	%d\n",clock->tm_hour);
	printf("minute	%d\n",clock->tm_min);
	printf("second	%d.%ld\n",clock->tm_sec,time.tv_usec);
	return 0;
}// It can measure 1 microsecond
//This timer is very accurate
